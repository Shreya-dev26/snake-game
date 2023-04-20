#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>

using namespace std;

const int width = 15;
const int height = 15;
//int x, y;
int x = width / 2;
int y = height / 2;
int falx=x-1, faly=y;
enum direc { STOP=0, LEFT, RIGHT, UP, DOWN };
direc dir;
bool gameOver;
int score = 0;
//int S[width];
int sheputx[30], sheputy[30];
int prevx= x, prevy= y;


void def() {
	gameOver = false;
	//srand(time(0));
	//falx = (rand() % width) + 1;
	//faly = (rand() % height) + 1;
}
void board() {

	system("cls");
	int B[width][height];
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			B[i][j];
			if (i == 0 || j == 0) {
				//B[i][j] = '*';
				cout << "*";
			}
			else if (i == width - 1 || j == height - 1) {
				//B[i][j] = '*';
				cout << "*";
			}
			else if (i == y && j == x) {
				cout << "@";
			}
			else if (i == faly && j == falx) {
				cout << "$";
			}
			else {
				cout << " ";
			}

		}
		cout << endl;

	}

}

void key() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a': dir = LEFT;
			break;
		case 'd': dir = RIGHT;
			break;
		case 'w': dir = UP;
			break;
		case 's': dir = DOWN;
			break;
		case 'k':
			gameOver = true;

			break;

		}

	}


}

void movement() {
	 
	switch (dir) {
	case LEFT:
		/*if (x == falx && y == faly) {
			for (x = falx; x < x + score; x++) {
				prevx = x;
				prevy = y;
			}
		}*/
		
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
		//default:
			//break;
	}
	if(y==0 || y==height || x==0 || x==width){
		gameOver = true;
	}
	if (x == falx && y == faly) {
		score = score +1;
		//falx = (rand() % width) + 1;
		//faly = (rand() % height) + 1;
		
	}
	
}

void sheput() {
	 switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		}
	
	}



int main() {
	def();
	

	while (!gameOver) {

		board();
		key();
		movement();
		sheput();

		cout << score;
		Sleep(50);
	}
	
	//Console.ReadKey(true);
	return 0;
}