// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyStruct.h"
#include <set>
#include "MyTestCPPLib.generated.h"
UCLASS()
class SAMPLECHAT_API UMyTestCPPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MyTestCPPLib")
	static FString GetMyFirstCPP();
	UFUNCTION(BlueprintCallable, Category = "MyTestCPPLib")
	static FAnswerResult IsAnswer(FString Text1);
	UFUNCTION(BlueprintCallable, Category = "MyTestCPPLib")
	static FString RandomInt();
	UFUNCTION(BlueprintCallable, Category = "MyTestCPPLib")
	static FBallGameResult Verdict(FString Random, FString UserAnswer);
};

