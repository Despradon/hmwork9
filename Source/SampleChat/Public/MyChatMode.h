// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyStruct.h"
#include "MyChatMode.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API AMyChatMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category = "MyTestCPPLib")
	static FAnswerResult IsAnswer(FString Text1);
};
