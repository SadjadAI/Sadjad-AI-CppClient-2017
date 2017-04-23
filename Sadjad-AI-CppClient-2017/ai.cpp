#include "stdafx.h"
#include "ai.h"

using namespace System;

//Change Server Address and token in Sadjad-AI-CppClient-2017.cpp
//You can use .net framework 4.5.2 in your project

void doTurn(int* index, Object^ Data) 
{

	Random^ rnd = gcnew Random();

	index[0] = rnd->Next(0, 9);
	index[1] = rnd->Next(0, 9);
}