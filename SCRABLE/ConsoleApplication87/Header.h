#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <clocale>
#include <ctime>
#include <cstring>
#include <cmath>
#include <fstream>
using namespace std;
int n;
const int M = 1000;
struct Player {
	char name[20];
	char letters[8];
	char words[30][20];
	int num_words=0;
	int score=0;
};
struct Dictionary {
	char word[20];
	char descript[1000];
};
Player *player;
Dictionary *words;
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
WORD def = 176;
WORD activ = 79;
WORD green = 47;
WORD light_blue = 191;
WORD blue = 159;
WORD pink = 223;
WORD red = 207;
WORD gray = 143;
WORD chip = 15;
const int N = 15;
char board[N][N];
int x = 0;
int y = 0;
int x_word = 0;
int y_word = 17;
char word[15];
char new_word[15];
int word_num = 7;
int x_prev = 0;
int y_prev = 0;
int prev_num = 0;
int x_w[20], y_w[20];
int num = 0;
char temp[10];
int esc_x[15], esc_y[15];
int esc_num = 0;
bool first = true;
char mode_of_game;
int x_neww=0;
int y_neww=0;
int ind = 0;
int pl1_word=0;
int pl0_word=0;
int pl1_num = 0;
int pl0_num = 0;