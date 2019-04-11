// Fill out your copyright notice in the Description page of Project Settings.

#include "EventManager.h"
#include "Engine.h"

TMap<FString, TArray<UObject*>> UEventManager::AllListener;

void UEventManager::AddEventListener(FString EventName, UObject* Listener)
{
	if (EventName == "" || Listener == nullptr)
	{
		return;
	}

	Listener->AddToRoot();

	TArray<UObject*>* arr = AllListener.Find(EventName);
	if (arr == nullptr || arr->Num() == 0)
	{
		TArray<UObject*> arr1 = { Listener };
		AllListener.Add(EventName, arr1);
	}
	else
	{
		arr->Add(Listener);
	}
}

void UEventManager::RemoveEventListener(FString EventName, UObject* Listener)
{
	TArray<UObject*>* arr = AllListener.Find(EventName);
	
	if (arr != nullptr&&arr->Num() > 0)
	{
		arr->Remove(Listener);
		Listener->RemoveFromRoot();
		Listener = nullptr;
	}
}

FString UEventManager::DispatchEvent(FString EventName, UObject* Datas)
{
	TArray<UObject*>* arr = AllListener.Find(EventName);

	if (arr==nullptr||arr->Num()==0)
	{
		return "'" + EventName + "NoListener.";
	}

	FString errorInfo = "";

	for (int i = 0; i < arr->Num(); i++)
	{
		UObject* obj = (*arr)[i];

		UFunction* fun = obj->FindFunction("ExecuteFun");
		if (fun == nullptr)
		{
			errorInfo = "'" + obj->GetName() + "No 'ExecuteFun' Function. \n";
		}
		else
		{
			obj->ProcessEvent(fun, &Datas);
		}
	}

	return errorInfo;
}

UObject* UEventManager::NewAsset(UClass* ClassType)
{
	UObject* obj = NewObject<UObject>(GetTransientPackage(), ClassType);
	obj->AddToRoot();
	return obj;
}
