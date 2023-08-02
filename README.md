# GreedyRobot
A robot is positioned on an integral point in a two-dimensional coordinate grid (xr, yr). There is
a treasure that has been placed at a point in the same grid at (xt, yt). All x’s and y’s will be
integral values. The robot can move up (North), down (South), left (West), or right (East).
Commands can be given to the robot to move one position in one of the four direction. That is,
“E” moves a robot one slot East (to the right) so if the robot was on position (3, 4), it would now
be on (4, 4). The command N would move the robot one position north so a robot at position
(4, 4) would be at (4, 5).


Because the robot cannot move diagonally, the shortest distance between a robot at (xr, yr) and
a treasure at (xt, yt) is
| xr – xt | + | yr - yt | = ShortestPossibleDistance


Write a recursive program which determines all the unique shortest possible paths from the
robot to the treasure with the following stipulation: The robot may never move in the same
direction more than max_distance times in a row.


The input to the program will be the max_distance value followed by the position of the robot
(xr, yr), followed by the position of the treasure (xt, yt). Assume that all five are integers and do
not worry about error conditions in inputs. Take these parameters as arguments to the
program on the command line.


Invoking greed_robot:

% greedy_robot max_distance robot_x robot_y treasure_x treasure_y

max_distance: maximum number of moves in one direction before a turn is required

robot_x: starting X coordinate of robot

robot_y: starting Y coordinate of robot

treasure_x: X coordinate of treasure

treasure_y: Y coordinate of treasure


For instance, an input of 2 1 3 -2 4 corresponds to the robot starting at position (1, 3) and
needing to get to the treasure at position (-2, 4) with the constraints that one can only move 2
steps in one direction before having to shift to a new position.


The output of the program should be the listing of all the unique shortest possible paths
followed by the number of unique paths. The paths must follow the stipulation whereby the
robot cannot move in the same direction more than max_distance times in a row. A path
should be output as a string of characters with each character corresponding to a direction the
Robot should move. For instance, NNEEENENE corresponds to having the robot move North,
North, East, East, East, North, East, North, East. This would be one answer to the input: 3 1 2 6
6, which corresponds to (1, 2) -> (6,6) with a max_distance of 3.


Notice that not all combinations of robots / treasures will have a solution. As there may not be
a ShortestPossibleDistance given the stipulation. For instance, 2 3 3 3 7 has shortest possible
distance of 4 but no way to get there in that distance without going North more than 2 times in
a row.


For the input 2 1 2 3 5 which corresponds to (1,2) -> (3,5) the output should be:

% greedy_robot 2 1 2 3 5

NNENE

NNEEN

NENNE

NENEN

NEENN

ENNEN

ENENN

Number of paths: 7
