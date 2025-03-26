// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyStruct.generated.h"

class SAMPLECHAT_API MyStruct
{
public:
	MyStruct();
	~MyStruct();
};

USTRUCT(BlueprintType)
struct FAnswerResult
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = "Test")
    bool BAnswer;

    UPROPERTY(BlueprintReadWrite, Category = "Test")
    FString MSG;
};

USTRUCT(BlueprintType)
struct FBallGameResult
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, Category = "Test")
    int Strike;

    UPROPERTY(BlueprintReadWrite, Category = "Test")
    int Ball;

    UPROPERTY(BlueprintReadWrite, Category = "Test")
    int OutCount; // 'Out' 대신 다른 이름 사용
};