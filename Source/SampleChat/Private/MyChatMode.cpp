// Fill out your copyright notice in the Description page of Project Settings.


#include "MyChatMode.h"


FAnswerResult AMyChatMode::IsAnswer(FString Text1)
{
    FAnswerResult ReturnValue;
    FString Numbers;
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
    for (TCHAR Char : Numbers)
    {
        if (!FChar::IsDigit(Char))
        {
            Digit = false;
            ReturnValue.BAnswer = false;
            return ReturnValue;
        }
    }
    //당연히 안오겠지만 혹시 모르니
    if (Digit == true)
    {
        if (Text1.Len() > 4)
        {
            ReturnValue.BAnswer = false;
        }
    }

    return ReturnValue;
}