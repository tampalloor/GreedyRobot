#ifndef GREEDY_ROBOT_H_
#define GREEDY_ROBOT_H_

#include<iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
class GreedyRobot
{

public:

	//coordinates for Robot and treausre
	struct Coordinates{
		int x;
		int y;
	};

	//constructors 
	GreedyRobot(); 
	GreedyRobot(int max, int Rx, int Ry, int Tx, int Ty); 

	//getters-setters
	int max_distance(); 
	int robot_x(); 
	int robot_y(); 
	int treasure_x(); 
	int treasure_y(); 
	int paths();

	void Set_Robot_Coordinates(int x, int y);
	void Set_Treasure_Coordinates(int x, int y);
	void Set_Max_Distance(int x);

	//actions
	void Path_Finder(int RobotX, int RobotY,  string pathSoFar);
	void Path_Finder_Opp(int RobotX, int RobotY, string pathSoFar);
	bool Duplicate(string pathSoFar);
	bool Max_Direction_N(string pathSoFar);
	bool Max_Direction_E(string pathSoFar);
	bool Max_Direction_S(string pathSoFar);
	bool Max_Direction_W(string pathSoFar);
	void Print();
	void Num_Paths();

	//operator overloads
	bool operator==(const GreedyRobot& robot) const;
	bool operator>=(const GreedyRobot& robot) const; 
	bool operator>(const GreedyRobot& robot) const;
	bool operator<=(const GreedyRobot& robot) const;
	bool operator<(const GreedyRobot& robot) const;
	bool operator!=(const GreedyRobot& robot) const;
	GreedyRobot& operator=(const GreedyRobot& robot);


private: 
	//private variables
	vector<string> all_paths_;
	int max_distance_;
	Coordinates robot_;
	Coordinates treasure_;
	int paths_;
};
#endif

