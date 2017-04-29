// Sadjad-AI-CppClient-2017.cpp : main project file.

#include "stdafx.h"
#include "ai.h"
#include "model.h"

using namespace System;
using namespace Threading;
using namespace Threading::Tasks;
using namespace Sadjad_AI_CppClient_2017_ClassLibrary;
using namespace Newtonsoft::Json;
using namespace Newtonsoft::Json::Linq;

int main(array<System::String ^> ^args)
{
	try
	{
		//Don't Change here
		SocketIO^ socket = gcnew SocketIO();
		int index[2];

		//Enter Server Address and your token
		socket->Server = "http://localhost:5000/game";
		socket->Token = 321;

		//Don't Change here
		socket->Connect();
		String^ state = socket->State;
		Console::WriteLine(state);

		while (true)
		{
			socket->Resive();
			JObject^ OResource = JObject::FromObject(socket->Data);
			Int32^ Score = Convert::ToInt32(OResource["score"]);
			Int32^ TurnNumber = Convert::ToInt32(OResource["turn_number"]);
			JArray^ AResource = JArray::Parse(OResource["data"]->ToString());

			std::vector<Cell*> Map;
			
			for each (auto items in AResource)
			{
				for each (auto item in items) 
				{
					if (item["type"]->ToString() == "black")
					{
						Cell *JB = new Cell(NoDirection, Black, JailedBird, 0);
						Map.push_back(JB);
					}
					else if (item["type"]->ToString() == "red")
					{
						Cell *JB = new Cell(NoDirection, Red, JailedBird, 0);
						Map.push_back(JB);
					}
					else if (item["type"]->ToString() == "green")
					{
						Cell *JB = new Cell(NoDirection, Green, JailedBird, 0);
						Map.push_back(JB);
					}
					else if (item["type"]->ToString() == "blue")
					{
						Cell *JB = new Cell(NoDirection, Blue, JailedBird, 0);
						Map.push_back(JB);
					}
					else if (item["type"]->ToString() == "yellow")
					{
						Cell *JB = new Cell(NoDirection, Yellow, JailedBird, 0);
						Map.push_back(JB);
					}
					else if (item["type"]->ToString() == "bomb")
					{
						Cell *JB = new Cell(NoDirection, NoColor, Bomb, 0);
					}
					else if (item["type"]->ToString() == "laser")
					{
						Int32 color = 0;

						if (item["color"]->ToString() == "black")
						{
							color = Black;
						}
						else if (item["color"]->ToString() == "red")
						{
							color = Red;
						}
						else if (item["color"]->ToString() == "green")
						{
							color = Green;
						}
						else if (item["color"]->ToString() == "blue")
						{
							color = Blue;
						}
						else if (item["color"]->ToString() == "yellow")
						{
							color = Yellow;
						}

						Cell *laser = new Cell(NoDirection, color, Laser, 0);
						Map.push_back(laser);

					}
					else if (item["type"]->ToString() == "rocket")
					{
						Int32 direction = 0;
						if (item["direction"]->ToString() == "0")
						{
							direction = 0;
						}
						else 
						{
							direction = 1;
						}
						Cell *rocket = new Cell(direction, NoColor, Rocket, 0);
						Map.push_back(rocket);
					}
					else if (item["type"]->ToString() == "glass")
					{
						Cell *glass = new Cell(NoDirection, NoColor, Glass, Convert::ToInt32(item["life_time"]->ToString()));
						Map.push_back(glass);
					}
					else if (item["type"]->ToString() == "wood")
					{
						Cell *wood = new Cell(NoDirection, NoColor, Wood, Convert::ToInt32(item["life_time"]->ToString()));
						Map.push_back(wood);
					}
					else if (item["type"]->ToString() == "rock")
					{
						Cell *rock = new Cell(NoDirection, NoColor, Wood, Convert::ToInt32(item["life_time"]->ToString()));
						Map.push_back(rock);
					}
				}
			}

			Board *board = new Board((int)Score, (int)TurnNumber, Map);
			//Console::WriteLine(data);
			doTurn(index, board);

			socket->Send(index[0], index[1]);
		}
	}
	catch (const std::exception& e)
	{
		Console::WriteLine("Error");
	}
	

    return 0;
}
