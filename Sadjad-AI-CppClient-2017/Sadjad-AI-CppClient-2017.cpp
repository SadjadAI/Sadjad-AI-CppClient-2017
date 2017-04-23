// Sadjad-AI-CppClient-2017.cpp : main project file.

#include "stdafx.h"
#include "ai.h"

using namespace System;
using namespace Threading;
using namespace Threading::Tasks;
using namespace Sadjad_AI_CppClient_2017_ClassLibrary;
using namespace Newtonsoft::Json;

int main(array<System::String ^> ^args)
{
	//Don't Change here
	SocketIO^ socket = gcnew SocketIO();
	int index[2];

	//Enter Server Address and your token
	socket->Server = "http://localhost:5000/game";
	socket->Token = 123;

	//Don't Change here
	socket->Connect();
	String^ state = socket->State;
	Console::WriteLine(state);
	
	while (true)
	{
		socket->Resive();
		Object^ data = socket->Data;
		doTurn(index, data);

		socket->Send(index[0], index[1]);

	}

    return 0;
}
