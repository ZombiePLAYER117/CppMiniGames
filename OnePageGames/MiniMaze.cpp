#include <iostream>
#include <conio.h>
using namespace std;

class MazeGame
{
public:
	void draw() {
		system( "cls" );
		cout << "---勇闯迷宫---" << endl;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (map[i][j]==1){
					cout << "@"; //@ is wall
				}
				else if (map[i][j] == 0) {
					cout << " "; //" "is the way
				}
				else if(map[i][j]==3)
				{
					cout << "♂"; //♂ is the player
				}
				else if (map[i][j] == 2) {
					cout << "E"; //E is end;
				}
			}
			cout << endl;
		}

	}
	void move(char direction) {
		int next_x = Player_x;
		int next_y = Player_y;
		if (direction == 'w') next_x--;
		else if (direction == 's') next_x++;
		else if (direction == 'a') next_y--;
		else if (direction == 'd') next_y++;
		else if (direction == 'q') { isRunning = false; cout << "you quited the game~"; };

		//collicion test
		if (map[next_x][next_y] != 1) {
			if (map[next_x][next_y] == 2) {
				draw();
				cout << "Congratulations！you escaped the maze successfully!";
				isRunning = false;
			}
			// reflash the data
			map[Player_x][Player_y] = 0;
			Player_x = next_x;
			Player_y = next_y;
			map[Player_x][Player_y] = 3;

		}
	}

	void setExit() { isRunning = false; }

	bool gameLoop(){
		return isRunning;
	};
private:
	//0：空地，1：墙 2：终点 3：玩家
	int map[8][8] = {
		{1,1,1,1,1,1,1,1},
		{1,3,0,0,0,0,0,1},
		{1,1,1,0,1,1,0,1},
		{1,0,0,0,0,1,0,1},
		{1,0,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,1},
		{1,0,0,0,1,1,2,1},
		{1,1,1,1,1,1,1,1},
	};
	int Player_x = 1;
	int Player_y = 1;
	bool isRunning = true;
};

int main() {
	MazeGame game;
	while (game.gameLoop()) {
		game.draw();
		char input = _getch();
		game.move(input);
	}
	return 0;
}