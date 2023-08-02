#include "greedy_robot.h"
/* Program 2, Problem 2 (Greedy Robot)
* 
* Thomas Ampalloor
* 
* Takes in 5 integers from the user and finds all shortest possible paths toward the treasure coordinates
*/
using namespace std; 
GreedyRobot::GreedyRobot()
{
	max_distance_ = 1; 
	robot_.x = 0; 
	robot_.y = 0; 
	treasure_.x = 1; 
	treasure_.y = 1; 
	paths_ = 0;

	Path_Finder(robot_.x, robot_.y, "");
	Path_Finder_Opp(robot_.x, robot_.y, "");
	Print();
	Num_Paths(); 
}

GreedyRobot::GreedyRobot(int max, int Rx, int Ry, int Tx, int Ty)
{
	max_distance_ = max; 
	robot_.x = Rx; 
	robot_.y = Ry; 
	treasure_.x = Tx; 
	treasure_.y = Ty;
	paths_ = 0;

	Path_Finder(robot_.x, robot_.y, "");
	Path_Finder_Opp(robot_.x, robot_.y, "");
	Print();
	Num_Paths();
}
void GreedyRobot::Num_Paths()
{
	if (robot_.x == treasure_.x && robot_.y == treasure_.y) {
		this->paths_ = 0;
		cout << "Number of paths: " << this->paths() << endl;
	}
	else {
		cout << "Number of paths: " << this->paths() << endl;

	}
}


bool GreedyRobot::Max_Direction_N(string pathSoFar)
{
	int count = 0;
	int pathStringLength = pathSoFar.length();
	if (pathStringLength == 0 || (pathStringLength == 1 && max_distance_ > 1)) {
		return false; 
	}
	int index = pathStringLength - 1;
	for (int i = index; i >= 0; i--) {
		if (pathSoFar.at(i) == 'N') {
			count++;
		}
		else if (pathSoFar.at(i) != 'N') {
			break;
		}
	}


	if (count >= max_distance_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::Max_Direction_E(string pathSoFar)
{
	int count = 0;
	int pathStringLength = pathSoFar.length();
	if (pathStringLength == 0 || pathStringLength == 1) {
		return false;
	}
	int index = pathStringLength - 1;

	for (int i = index; i >= 0; i--) {
		if (pathSoFar.at(i) == 'E') {
			count++;
		}
		else if (pathSoFar.at(i) != 'E') {
			break;
		}
	}

	if (count >= max_distance_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::Max_Direction_S(string pathSoFar)
{

	int count = 0;
	int pathStringLength = pathSoFar.length();
	if (pathStringLength == 0 || pathStringLength == 1) {
		return false;
	}
	int index = pathStringLength - 1;

	for (int i = index; i >= 0; i--) {
		if (pathSoFar.at(i) == 'S') {
			count++;
		}
		else if (pathSoFar.at(i) != 'S') {
			break;
		}
	}

	if (count >= max_distance_) {
		return true;
	}
	else {
		return false;
	}
}


bool GreedyRobot::Max_Direction_W(string pathSoFar)
{

	int count = 0;
	int pathStringLength = pathSoFar.length();
	if (pathStringLength == 0 || pathStringLength == 1) {
		return false;
	}
	int index = pathStringLength - 1;

	for (int i = index; i >= 0; i--) {
		if (pathSoFar.at(i) == 'W') {
			count++;
		}
		else if (pathSoFar.at(i) != 'W') {
			break;
		}
	}

	if (count >= max_distance_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::Duplicate(string pathSoFar)
{
	if (all_paths_.size() != 0) {
		for (int i = 0; i < all_paths_.size(); i++) {
			if (all_paths_.at(i) == pathSoFar) {
				return true;
			}
		}
	}
	else {
		return false; 
	}

	return false;
}

void GreedyRobot::Print() {

	char previous;
	int count = 0;
	for (int i = 0; i < all_paths_.size(); i++) {
		string path = all_paths_.at(i);
		count = 0;
		for (int j = 0; j < path.size(); j++) {
			if (j == 0) {
				previous = path.at(j); 
				count++;
			}
			else if (previous == path.at(j)){
				count++;

				if (count > max_distance_) {
					break;
				}
			}
			else {
				count = 1;
				previous = path.at(j);
			}
		}

		if (count <= max_distance_) {
			cout << path << endl;
			paths_++;
		}

	}
}

void GreedyRobot::Path_Finder(int RobotX, int RobotY, string pathSoFar)
{
	if (RobotX < treasure_.x && RobotY < treasure_.y) {  //East and North (North East) 

		if (!Max_Direction_N(pathSoFar)) {

			RobotY++; 
			pathSoFar = pathSoFar + "N";
			Path_Finder(RobotX, RobotY, pathSoFar);
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}

		if (!Max_Direction_E(pathSoFar)) {
			RobotX++;
			pathSoFar = pathSoFar + "E";
			Path_Finder(RobotX, RobotY, pathSoFar);
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}

	}
	else if (RobotX < treasure_.x && RobotY > treasure_.y) { // East and South (South East) 
		if (!Max_Direction_S(pathSoFar)) {
			RobotY--;
			pathSoFar = pathSoFar + "S";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
		if (!Max_Direction_E(pathSoFar)) {
			RobotX++;
			pathSoFar = pathSoFar + "E";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
	}
	else if (RobotX > treasure_.x && RobotY < treasure_.y) { //North and West (North West) 
		if (!Max_Direction_N(pathSoFar)) {
			RobotY++;
			pathSoFar = pathSoFar + "N";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
		if (!Max_Direction_W(pathSoFar)) {
			RobotX--;
			pathSoFar = pathSoFar + "W";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
	}
	else if (RobotX > treasure_.x && RobotY > treasure_.y) { //South and West (South West) 
		if (!Max_Direction_S(pathSoFar)) {
			RobotY--;
			pathSoFar = pathSoFar + "S";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
		if (!Max_Direction_W(pathSoFar)) {
			RobotX--;
			pathSoFar = pathSoFar + "W";
			Path_Finder(RobotX, RobotY, pathSoFar);
		}
	}
	else if (RobotX == treasure_.x && RobotY == treasure_.y) {

		if (!Duplicate(pathSoFar)) {
			all_paths_.push_back(pathSoFar);
		}

	}
	else if (RobotX == treasure_.x) {
		if (RobotY > treasure_.y) {
			if (max_distance_ >= (RobotY - treasure_.y)) {
				int length = RobotY - treasure_.y;

				while (length > 0) {
					pathSoFar += "S";
					length--;
				}

				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
		else if (RobotY < treasure_.y) {
			if (max_distance_ >= (treasure_.y - RobotY)) {
				int length = treasure_.y - RobotY;

				while (RobotY != treasure_.y) {
					pathSoFar += "N";
					RobotY++;
				}

				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}

		}
	}
	else if (RobotY == treasure_.y) {
		if (RobotX > treasure_.x) {
			if (max_distance_ >= (RobotX - treasure_.x)) {
				int length = RobotX - treasure_.x;

				while (length > 0) {
					pathSoFar += "W";
					length--;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
		else if (RobotX < treasure_.x) {
			if (max_distance_ >= (treasure_.x - RobotX)) {
				int length = treasure_.x - RobotX;

				while (length > 0) {
					pathSoFar += "E";
					length--;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
	}
	else {
		cout << "Number of paths: 0" << endl;
	}
}

void GreedyRobot::Path_Finder_Opp(int RobotX, int RobotY, string pathSoFar)
{
	if (RobotX < treasure_.x && RobotY < treasure_.y) {  //East and North (North East) 
		if (!Max_Direction_E(pathSoFar)) {
			RobotX++;
			pathSoFar = pathSoFar + "E";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
			Path_Finder(RobotX, RobotY, pathSoFar);

		}

		if (!Max_Direction_N(pathSoFar)) {

			RobotY++;
			pathSoFar = pathSoFar + "N";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
			Path_Finder(RobotX, RobotY, pathSoFar);

		}

	}
	else if (RobotX < treasure_.x && RobotY > treasure_.y) { // East and South (South East) 
		if (!Max_Direction_E(pathSoFar)) {
			RobotX++;
			pathSoFar = pathSoFar + "E";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}
		if (!Max_Direction_S(pathSoFar)) {
			RobotY--;
			pathSoFar = pathSoFar + "S";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}

	}
	else if (RobotX > treasure_.x && RobotY < treasure_.y) { //North and West (North West) 
		if (!Max_Direction_W(pathSoFar)) {
			RobotX--;
			pathSoFar = pathSoFar + "W";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}
		
		if (!Max_Direction_N(pathSoFar)) {
			RobotY++;
			pathSoFar = pathSoFar + "N";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}

	}
	else if (RobotX > treasure_.x && RobotY > treasure_.y) { //South and West (South West) 
		if (!Max_Direction_W(pathSoFar)) {
			RobotX--;
			pathSoFar = pathSoFar + "W";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}
		if (!Max_Direction_S(pathSoFar)) {
			RobotY--;
			pathSoFar = pathSoFar + "S";
			Path_Finder_Opp(RobotX, RobotY, pathSoFar);
		}

	}
	else if (RobotX == treasure_.x && RobotY == treasure_.y) {
		if (!Duplicate(pathSoFar)) {
			all_paths_.push_back(pathSoFar);
		}
	}
	else if (RobotX == treasure_.x) {

		if (RobotY > treasure_.y) {
			if (max_distance_ >= (RobotY - treasure_.y)) {
				int length = RobotY - treasure_.y;

				while (length > 0) {
					pathSoFar += "S";
					length--;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
		else if (RobotY < treasure_.y) {

			if (max_distance_ >= (treasure_.y - RobotY)) {
				int length = treasure_.y - RobotY;
				while (RobotY != treasure_.y ) {
					pathSoFar += "N";
					RobotY++;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
				
			}

		}
	}
	else if (RobotY == treasure_.y) {
		if (RobotX > treasure_.x) {
			if (max_distance_ >= (RobotX - treasure_.x)) {
				int length = RobotX - treasure_.x;

				while (length > 0) {
					pathSoFar += "W";
					length--;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
		else if (RobotX < treasure_.x) {
			if (max_distance_ >= (treasure_.x - RobotX)) {
				int length = treasure_.x - RobotX;

				while (length > 0) {
					pathSoFar += "E";
					length--;
				}
				if (!Duplicate(pathSoFar)) {
					all_paths_.push_back(pathSoFar);
				}
			}
		}
	}
	else {
		cout << "Number of paths: 0" << endl;
	}
}

int GreedyRobot::max_distance()
{
	return max_distance_;
}

int GreedyRobot::robot_x()
{
	return robot_.x;
}

int GreedyRobot::robot_y()
{
	return robot_.y; 
}

int GreedyRobot::treasure_x()
{
	return treasure_.x;
}

int GreedyRobot::treasure_y()
{
	return treasure_.y;
}

int GreedyRobot::paths()
{
	return paths_;
}

void GreedyRobot::Set_Robot_Coordinates(int x, int y)
{
	robot_.x = x; 
	robot_.y = y; 
}

void GreedyRobot::Set_Treasure_Coordinates(int x, int y)
{
	treasure_.x = x; 
	treasure_.y = y; 
}

void GreedyRobot::Set_Max_Distance(int x)
{
	max_distance_ = x;
}

//return true if they have the same number of paths
bool GreedyRobot::operator==(const GreedyRobot& robot) const
{
	if (this->paths_ == robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::operator>=(const GreedyRobot& robot) const
{
	if (this->paths_ >= robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::operator>(const GreedyRobot& robot) const
{
	if (this->paths_ > robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::operator<=(const GreedyRobot& robot) const
{
	if (this->paths_ <= robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::operator<(const GreedyRobot& robot) const
{
	if (this->paths_ < robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

bool GreedyRobot::operator!=(const GreedyRobot& robot) const
{
	if (this->paths_ != robot.paths_) {
		return true;
	}
	else {
		return false;
	}
}

GreedyRobot& GreedyRobot::operator=(const GreedyRobot& robot)
{
	this->max_distance_= robot.max_distance_;
	this->robot_.x = robot.robot_.x;
	this->robot_.y = robot.robot_.y;
	this->treasure_.x = robot.treasure_.x;
	this->treasure_.y = robot.treasure_.y;


	return *this;
}
