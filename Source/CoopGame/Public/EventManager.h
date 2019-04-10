// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EventManager.generated.h"

/**
 * 
 */
UCLASS()
class COOPGAME_API UEventManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
private:
	static TMap<FString, TArray<UObject*>> AllListener;

public:
	static void AddEventListener(FString EventName, UObject* Listener);

	static void RemoveEventListener(FString EventName, UObject* Listener);

	static FString DispatchEvent(FString EventName, UObject* Datas);

	UFUNCTION(BlueprintCallable, Category="EventDispatchUtility")
	static UObject* NewAsset(UClass* ClassType);
};
