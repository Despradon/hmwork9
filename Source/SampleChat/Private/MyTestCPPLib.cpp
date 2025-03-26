// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestCPPLib.h"
#include <unordered_set>

using namespace std;

FString UMyTestCPPLib::GetMyFirstCPP()
{
    return FString(TEXT("Hello CPP lib in BP"));
}

FAnswerResult UMyTestCPPLib::IsAnswer(FString Text1)
{
    FAnswerResult ReturnValue;
    FString Numbers;
    //��������ʰ� '/'�� �����ϴ��� �˻� �´ٸ� �ϴ� Answer�� true�� �ٲٰ� /�� ������ ���ڿ��� �޴´�
    if (!Text1.IsEmpty() && Text1[0] == '/')
    {
        ReturnValue.BAnswer = true;
        ReturnValue.MSG = Text1.RightChop(1);
        Numbers = ReturnValue.MSG;
    }
    else
    {
        ReturnValue.BAnswer = false;
        ReturnValue.MSG = TEXT("");
    }
    bool Digit = true;
    set<char> SameThing; // �ٸ� ����3������ Ȯ��
    for (TCHAR Char : Numbers)
    {
        SameThing.insert(Char);
        if (!FChar::IsDigit(Char))
        {
            Digit = false;
            ReturnValue.BAnswer = false;
            return ReturnValue;
        }
    }
    //set�� Ư���� �ߺ��� �ڵ��������ֱ⿡ ���� ����3���� ���ڰ� �ߺ��� �ִٸ� 3�� �� �� ����
    if (SameThing.size() != 3)
    {
        Digit = false;
        ReturnValue.BAnswer = false;
        return ReturnValue;
    }
    //�翬�� �ȿ������� Ȥ�� �𸣴�
    if (Digit == true) 
    {
        if (Text1.Len() > 4)
        {
            ReturnValue.BAnswer = false;
        }
    }

    return ReturnValue;
}

FString UMyTestCPPLib::RandomInt()
{
    unordered_set<int> Result;
    while (Result.size() < 3)
    {
        int RandomInt = FMath::RandRange(1, 9);
        Result.insert(RandomInt);
    }
    FString OutString;
    for (int Num : Result)
    {
        OutString += FString::FromInt(Num);
    }

    return OutString;
}

FBallGameResult UMyTestCPPLib::Verdict(FString Random,FString UserAnswer)
{
    FBallGameResult Result;
    int Strike =0, Ball = 0, Out =0;
    for (int i = 0; i < 3; i++)
    {
        bool Found = false;
        for (int j = 0; j < 3; j++)
        {
            if (Random[i] == UserAnswer[j])
            {
                if (i == j)
                    Strike++;
                else
                    Ball++;

                Found = true;
                break;
            }
        }
        if (Found == false)
            Out++;
    }
    Result.Ball = Ball;
    Result.Strike = Strike;
    Result.OutCount = Out;
    return Result;
}
