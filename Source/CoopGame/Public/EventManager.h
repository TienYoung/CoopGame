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

	UFUNCTION(BlueprintCallable, Category = "EventDispatchUtility")
	static void AddEventListener(FString EventName, UObject* Listener);

	UFUNCTION(BlueprintCallable, Category = "EventDispatchUtility")
	static void RemoveEventListener(FString EventName, UObject* Listener);

	UFUNCTION(BlueprintCallable, Category = "EventDispatchUtility")
	static FString DispatchEvent(FString EventName, UObject* Datas);

	UFUNCTION(BlueprintCallable, Category="EventDispatchUtility")
	static UObject* NewAsset(UClass* ClassType);
};
