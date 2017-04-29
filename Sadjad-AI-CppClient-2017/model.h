#pragma once
#include "stdafx.h"

enum color {
	NoColor = 0,
	Red = 1,
	Blue = 2,
	Yellow = 3,
	Black = 4,
	Green = 5
};

enum direction {
	NoDirection = 2,
	Horizontal = 1,
	Vertical = 0
};

enum type {
	JailedBird = 1,
	Bomb,
	Rocket,
	Laser,
	Glass,
	Wood,
	Rock,
};

public class Cell
{
public:
	Cell(int direction, int color, int type, int life_time)
	{
		this->type = type;
		this->color = color;
		this->direction = direction;
		this->life_time = life_time;
	}
	std::string get_type() 
	{
		switch (this->type)
		{
		case 1:
			return "JailedBird";
			break;
		case 2:
			return "Bomb";
			break;
		case 3:
			return "Rocket";
			break;
		case 4:
			return "Laser";
			break;
		case 5:
			return "Glass";
			break;
		case 6:
			return "Wood";
			break;
		case 7:
			return "Rock";
			break;
		}
	}
	std::string get_direction()
	{
		switch (this->direction)
		{
		case 1:
			return "Horizontal";
			break;
		case 2:
			return "NoDirection";
			break;
		case 0:
			return "Vertical";
			break;
		}
	}
	std::string get_color()
	{
		switch (this->color)
		{
		case 0:
			return "NoColor";
			break;
		case 1:
			return "Red";
			break;
		case 2:
			return "Blue";
			break;
		case 3:
			return "Yellow";
			break;
		case 4:
			return "Black";
			break;
		case 5:
			return "Green";
			break;
		}
	}
	int get_life_time()
	{
		return life_time;
	}
private:
	int type;
	int direction;
	int color;
	int life_time;
};


public class Board
{
public:
	Board(int score, int turn_number, std::vector<Cell*> map)
	{
		this->score = score;
		this->turn_number = turn_number;
		this->map = map;
	}
	int get_score()
	{
		return this->score;
	}
	int get_turn_number()
	{
		return this->turn_number;
	}
	std::vector<Cell*> get_map()
	{
		return map;
	}
private:
	int score;
	int turn_number;
	std::vector<Cell*> map;
};
