#pragma once
#include<iostream>
#include"Func.h"
void ClearAll()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = ' ';
		}
	}
}
void meaning_of_word()
{
	int y0_pos = 5;
	int x0_pos = 60;
	int y1_pos = 5;
	int x1_pos = 73;
	char ind_curs;
	char ind_curs1 = 0;
	int num_player = 0;
	int key=0; 
	int ind_pl = 0;
	gotoxy(60, y0_pos);
	SetConsoleTextAttribute(hStdOut, green);
	cout << "  ";
	SetConsoleTextAttribute(hStdOut, activ);
	if (player[0].words[pl0_word][0] == NULL) {
		cout << "-----";
	}
	else {
		cout << player[0].words[pl0_word];
	}
	while (true)
	{
		while (!_kbhit());
		ind_curs = _getch();
		switch (ind_curs)
		{
		case 77://right
		{
		
			if (pl1_num != 0 && key!=1)
			 {
				key = 1;
				pl1_word = 0;
				gotoxy(60, y0_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "  ";
				if (player[0].words[pl0_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[0].words[pl0_word];
				}
				y0_pos = 5;
				y1_pos = 5;
				pl0_word = 0;
				num_player = 1;
				gotoxy(73, 5);
				cout << "||  ";
				SetConsoleTextAttribute(hStdOut, activ);
				if (player[1].words[0][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[1].words[0];
				}
			}
			break;
		}
		case 75://left
		{
			
			if (key != 0)
			{
				key = 0;
				pl0_word = 0;
				gotoxy(x1_pos, y1_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "||  ";
					if (player[1].words[pl1_word][0] == NULL) {
						cout << "-----";
					}
					else {
						cout << player[1].words[pl1_word];
					}
					pl1_word = 0;
					y1_pos = 5;
					y0_pos = 5;
					gotoxy(60, 5);
					cout << "  ";
					SetConsoleTextAttribute(hStdOut, activ);
					if (player[key].words[0][0] == NULL) {
						cout << "-----";
					}
					else {
						cout << player[key].words[0];
					}
			}
			break;
		}
		case 80://down
		{
			if (key == 1&& y1_pos-4<player[1].num_words)
			{
				gotoxy(x1_pos, y1_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "||  ";
				if (player[1].words[pl1_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[1].words[pl1_word];
				}
				pl1_word++;
				y1_pos++;
				gotoxy(x1_pos, y1_pos);
				cout << "||  ";
				SetConsoleTextAttribute(hStdOut, activ);
				if (player[1].words[pl1_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[1].words[pl1_word];
				}
			}
			else if (key == 0 && y0_pos - 4 < player[0].num_words)
			{
				gotoxy(x0_pos, y0_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "  ";
				if (player[0].words[pl0_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[0].words[pl0_word];
				}
				pl0_word++;
				y0_pos++;
				gotoxy(x0_pos, y0_pos);
				cout << "  ";
				SetConsoleTextAttribute(hStdOut, activ);
				if (player[key].words[pl0_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[key].words[pl0_word];
				}
			}
			break;
		}
		case 72://up
		{
			if (key == 1 && y1_pos - 4 > 1)
			{
				gotoxy(x1_pos, y1_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "||  ";
				if (player[1].words[pl1_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[1].words[pl1_word];
				}
				pl1_word--;
				y1_pos--;
				gotoxy(x1_pos, y1_pos);
				cout << "||  ";
				SetConsoleTextAttribute(hStdOut, activ);
				if (player[1].words[pl1_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[1].words[pl1_word];
				}
			}
			else if (key == 0 && y0_pos - 4 > 1)
			{
				gotoxy(x0_pos, y0_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "  ";
				if (player[0].words[pl0_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[0].words[pl0_word];
				}
				pl0_word--;
				y0_pos--;
				gotoxy(x0_pos, y0_pos);
				cout << "  ";
				SetConsoleTextAttribute(hStdOut, activ);
				if (player[key].words[pl0_word][0] == NULL) {
					cout << "-----";
				}
				else {
					cout << player[key].words[pl0_word];
				}
			}
			break;
		}
		case 27://esc
		{
			pl1_word = 0;
			pl0_word = 0;
			PrintScore();
			break;
		}
		case 13://enter
		{
			char testword[20]="";
			char s[70] = "                                                    ";
			if (key == 1&& player[key].words[pl1_word][0]!=NULL)
			{
				SetConsoleTextAttribute(hStdOut, green);
				gotoxy(2, 30);
				cout << s;
				gotoxy(2, 31);
				cout << s;
				gotoxy(x1_pos, y1_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "||  ";
					cout << player[1].words[pl1_word];
					for (int i = 0; i < strlen(player[key].words[pl1_word]); i++)
					{
						testword[i] = player[key].words[pl1_word][i] + 32;
					}
					testword[strlen(player[key].words[pl1_word])] = NULL;
				gotoxy(4, 30);
				cout << "Descript of:" << testword;
				gotoxy(4, 31);
				
				if (Test(testword) < 0)
				{
					cout << "This word isn't have description:(enter 'c' to continue)";
				}
				else
				{
					cout << words[Test(testword)].descript<<endl<< "enter 'c' to continue";
				}
				
			}
			else if (key == 0&& player[key].words[pl0_word][0] != NULL)
			{
				SetConsoleTextAttribute(hStdOut, green);
				gotoxy(2, 30);
				cout << s;
				gotoxy(2, 31);
				cout << s;
				gotoxy(x0_pos, y0_pos);
				SetConsoleTextAttribute(hStdOut, green);
				cout << "  ";
					cout << player[0].words[pl0_word];
				gotoxy(4, 30);
				for (int i = 0; i < strlen(player[key].words[pl0_word]); i++)
				{
					testword[i] = player[key].words[pl0_word][i] + 32;

				}
				testword[strlen(player[key].words[pl0_word])] = NULL;
				cout << "Descript of:" << testword;
				gotoxy(4, 31);
				
				if (Test(testword) < 0)
				{
					cout << "This word isn't have description:(enter 'c' to continue)";
				}
				else
				{
					cout << words[Test(testword)].descript<<endl << "enter 'c' to continue";
				}
				
			}
			else
			{
				ind_curs = 0;
				break;
			}
			cin>>ind_curs1;
			if (ind_curs1 == 99)
			{
				pl1_word = 0;
				pl0_word = 0;
				key = 0;
				y0_pos = y1_pos = 5;
				SetConsoleTextAttribute(hStdOut, def);
				gotoxy(2, 30);
				cout << s;
				gotoxy(2, 31);
				for (int i = 0; i < 21; i++)
				{
					cout << s;
				}
				gotoxy(0, 0);
			}
			break;
		}
		}
		if (ind_curs == 27|| ind_curs == 13)
		{
			
			break;
		}
	}

}
void NewWord()
{ 
	int i;
	if (ind == 1)
	{ 
		while (board[y_neww - 1][x_neww] != ' ')
		{
			y_neww--;
			prev_num++;
		}
		for ( i = 0, y_neww; y_neww < y; y_neww++)
		{
			x_w[i] = x_neww;
			y_w[i] = y_neww;
			word[i] = board[y_neww][x_neww];
			i++;
		}
	}
	 else if (ind == 2)
	 {
		while (board[y_neww][x_neww-1] != ' ')
		{
			x_neww--;
			prev_num++;
		}
		for ( i = 0, x_neww; x_neww < x; x_neww++)
		{
			x_w[i] = x_neww;
			y_w[i] = y_neww;
			word[i] = board[y_neww][x_neww];
			i++;
		}
	 }

}

void PrintBoard()
{
	gotoxy(0, 0);
	SetConsoleTextAttribute(hStdOut, green);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			SetColor(j, i);
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
}

void PrintScore()
{
	SetConsoleTextAttribute(hStdOut, green);
	char s[50] = "                             ";
	for (int i = 0; i < 20; i++)
	{
		gotoxy(60, i + 2);
		cout << s;
	}
	gotoxy(70, 2);
	cout << "SCORE";
	gotoxy(60, 3);
	cout << "  " << player[0].name;
	gotoxy(73, 3);
	cout << "||  " << player[1].name;
	gotoxy(60, 4);
	cout << "  " << player[0].score;
	gotoxy(73, 4);
	cout << "||  " << player[1].score;
	for (int i = 0; i < player[0].num_words; i++) {
		gotoxy(60, i + 5);
		if (player[0].words[i][0] == NULL) {
			cout << "  -----";
		}
		else {
			cout << "  " << player[0].words[i];
			pl0_num++;
		}
	}
	for (int i = 0; i < player[1].num_words; i++) {
		gotoxy(73, i + 5);
		if (player[1].words[i][0] == NULL) {
			cout << "||  -----";
		}
		else {
			cout << "||  " << player[1].words[i];
			pl1_num++;
		}
	}
}

void PrintPlayer(int num)
{
	gotoxy(0, 16);
	SetConsoleTextAttribute(hStdOut, def);
	char s[50] = "                             ";
	cout << s << "\n" << s;

	gotoxy(0, 16);
	SetConsoleTextAttribute(hStdOut, gray);
	cout << "Player: " << player[num].name << "  " << endl;
	SetConsoleTextAttribute(hStdOut, green);
	for (int i = 0; i < word_num; i++) {
		cout << " " << player[num].letters[i] << " ";
	}
	cout << endl;
}

void gotoxy(int x, int y)
{
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, cursorPos);
}

void Active(int x, int y)
{
	gotoxy(x*3 , y);
	SetConsoleTextAttribute(hStdOut, activ);
	cout << " " << board[y][x] << " ";
}

void inActive(int x, int y)
{
	gotoxy(x * 3, y);
	SetColor(x, y);
	cout << " " << board[y][x] << " ";
}

void ActiveWord(int x, int y, int num)
{
	gotoxy(x * 3, y);
	SetConsoleTextAttribute(hStdOut, activ);
	cout << " " << player[num].letters[x] << " ";
}

void inActiveWord(int x, int y, int num)
{
	gotoxy(x * 3, y);
	SetConsoleTextAttribute(hStdOut, green);
	cout << " " << player[num].letters[x] << " ";
}

int Check(int x, int y)
{
	if ((x == 0 || x == 7 || x == 14) && (y == 3 || y == 11) || (x == 2 || x == 12) && (y == 6 || y == 8) || (x == 3 || x == 11) && (y == 0 || y == 7 || y == 14) || (x == 6 || x == 8) && (y == 2 || y == 6 || y == 8 || y == 12)) {
		return 1;
	}
	if (((x >= 1 && x <= 4) || (x >= 10 && x <= 13)) && ((y >= 1 && y <= 4) || (y >= 10 && y <= 13)) && (x == y || x == N - y - 1)) {
		return 2;
	}
	if ((x == 1 || x == 13) && (y == 5 || y == 9) || (x == 5 || x == 9) && (y == 1 || y == 5 || y == 9 || y == 13)) {
		return 3;
	}
	if ((x == 0 || x == 7 || x == 14) && (y == 0 || y == 7 || y == 14)) {
		return 4;
	}
	return 0;
}

void SetColor(int x, int y)
{
	if (board[y][x] != ' ') {
		SetConsoleTextAttribute(hStdOut, chip);
		return;
	}
	switch (Check(x, y)) {
	case 0: {
		SetConsoleTextAttribute(hStdOut, green);
		break;
	}
	case 1: {
		SetConsoleTextAttribute(hStdOut, light_blue);
		break;
	}
	case 2: {
		SetConsoleTextAttribute(hStdOut, pink);
		break;
	}
	case 3: {
		SetConsoleTextAttribute(hStdOut, blue);
		break;
	}
	case 4: {
		SetConsoleTextAttribute(hStdOut, red);
		break;
	}
	}
}

int ScoreWord()
{
	int add = 1;
	int sum = 0;
	for (int i = 0; i < prev_num; i++) {
		switch (Check(x_w[i], y_w[i])) {
		case 0: {
			sum += Score(word[i]);
			break;
		}
		case 1: {
			sum += Score(word[i]) * 2;
			break;
		}
		case 2: {
			sum += Score(word[i]);
			add *= 2;
			break;
		}
		case 3: {
			sum += Score(word[i]) * 3;
			break;
		}
		case 4: {
			sum += Score(word[i]);
			add *= 3;
			break;
		}
		}
	}
	return sum * add;
}

int Score(char latter)
{
	int sum = 0;

	switch (latter) {
	case 'L':
	case 'S':
	case 'U':
	case 'N':
	case 'R':
	case 'T':
	case 'O':
	case 'A':
	case 'I':
	case 'E':
	{
		sum += 1;
		break;
	}
	case 'G':
	case 'D':
	{
		sum += 2;
		break;
	}
	case 'B':
	case 'C':
	case 'M':
	case 'P':
	{
		sum += 3;
		break;
	}
	case 'F':
	case 'H':
	case 'V':
	case 'W':
	case 'Y':
	{
		sum += 4;
		break;
	}
	case 'K':
	{
		sum += 5;
		break;
	}
	case 'J':
	case 'X':
	{
		sum += 8;
		break;
	}
	case 'Q':
	case 'Z':
	{
		sum += 10;
		break;
	}
	}

	return sum;
}

int Test(char *word, int left, int right)
{
	int mid = (right + left) / 2;

	int ind = strcmp(words[mid].word, word);
	if (ind == 0) {
		return mid;
	}
	if (ind < 0 && mid < right - 1) {
		return Test(word, mid, right);
	}
	if (ind > 0 && left < mid - 1) {
		return Test(word, left, mid);
	}

	return -1;
}

int Connect(Dictionary **words)
{
	

	ifstream fin("scrabble2.txt");
	fin >> n;
	if (!fin.is_open()) {
		cout << "File not open" << endl;
	}
	else {

		*words = new Dictionary[n];
		for (int i = 0; i < n; i++) {
			fin >> (*words)[i].word;
			fin.getline((*words)[i].descript, M);
		}
	}
	fin.close();
	return n;
}

void AddWord(char *word)
{
	ofstream fout("scrabble2.txt");
	fout << n + 1 << endl;
	for (int i = 0; i < n; i++) {
		fout << words[i].word << words[i].descript << endl;
	}
	fout << word << endl;
	Connect(&words);
}
void StartGame()
{
	player = new Player[2];
	n = Connect(&words);
	SetConsoleTitle(L"SCRABLE. Lena Lavro");
	ClearAll();
	SetConsoleTextAttribute(hStdOut, def);
	system("cls");
	cout << "Please, chose mode of game\n";
	cout << "1.Press 'e'- easy mode(you can add new words to the dictionary)\n";
	cout << "2.Press other button - hard mode(you can't add new words to the dictionary)\n";
	cout << "Your choice:";
	cin >> mode_of_game;
	if (mode_of_game == 'e')
	{
		SetConsoleTitle(L"SCRABLE. Lena Lavro. Easy mode");
	}
	else SetConsoleTitle(L"SCRABLE. Lena Lavro. Hard mode");
	system("cls");
	cout << "Enter the name first player: ";
	cin >> player[0].name;
	system("cls");
	while (true)
	{
		cout << "Enter the name second player: ";
		cin >> player[1].name;
		system("cls");
		if (!strcmp(player[0].name, player[1].name))
		{
			cout << "Names are identical. Enter other name of second player."<<endl;
		}
		else
		{
			system("cls");
			break;
		}
	}
	for (int i = 0; i < 7; i++) {
		player[0].letters[i] = (char)(rand() % 26 + 'A');
		player[1].letters[i] = (char)(rand() % 26 + 'A');
	}
	player[0].letters[7] = NULL;
	player[1].letters[7] = NULL;
	PrintScore();
	PrintBoard();
	PrintPlayer(num);
	Active(x, y);
}
void Game()
{
	int key;
	strcpy_s(temp, player[num].letters);
	while (true) 
	{
		while (!_kbhit());

		key = _getch();
		switch (key) {
		case 77: {//right
			if (x < N - 1) {
				inActive(x, y);
				x++;
				Active(x, y);
			}
			break;
		}
		case 75: {//left
			if (x > 0) {
				inActive(x, y);
				x--;
				Active(x, y);
			}
			break;
		}
		case 80: {//down
			if (y < N - 1) {
				inActive(x, y);
				y++;
				Active(x, y);
			}
			break;
		}
		case 72: {//up
			if (y > 0) {
				inActive(x, y);
				y--;
				Active(x, y);
			}
			break;
		}
		case 13: {//enter
			int ind2 = 0;
			if (prev_num == 0) {
				ind2 = 1;
				x_neww = x;
				y_neww = y;
			}
			if (prev_num == 1) {
				if (x_prev == x && y_prev + 1 == y) {
					ind = 1;
					ind2 = 1;
					
				}
				if (y_prev == y && x_prev + 1 == x) {
					ind = 2;
					ind2 = 1;
					
				}
				NewWord();
			}
			if (prev_num > 1) {
				if (ind == 1 && x_prev == x && y_prev + 1 == y) {
					
					ind2 = 1;
				}
				if (ind == 2 && y_prev == y && x_prev + 1 == x){
					ind2 = 1; 
				
				}
			}

			if (ind2) {
				if (board[y][x] == ' ') {
					x_word = 0;
					key = 0;
					ActiveWord(x_word, y_word, num);
					while (key != 13 && key != 27) {
						while (!_kbhit());
						key = _getch();
						switch (key) {
						case 77: {//right
							if (x_word < word_num - 1) {
								inActiveWord(x_word, y_word, num);
								x_word++;
								ActiveWord(x_word, y_word, num);
							}
							break;
						}
						case 75: {//left
							if (x_word > 0) {
								inActiveWord(x_word, y_word, num);
								x_word--;
								ActiveWord(x_word, y_word, num);
							}
							break;
						}
						case 48://exit
						{
							exit(0);
							break;
						}
						}
					}
				
					inActiveWord(x_word, y_word, num);
					int len = strlen(player[num].letters);
					if (len > 0 && key != 27) {
						board[y][x] = player[num].letters[x_word];
						esc_x[esc_num] = x;
						esc_y[esc_num] = y;
						x_prev = x;//prev
						y_prev = y;
						x_w[prev_num] = x;
						y_w[prev_num] = y;
						word[prev_num] = board[y][x];
						prev_num++;
						esc_num++;
						for (int i = x_word; i < len - 1; i++) {
							player[num].letters[i] = player[num].letters[i + 1];
						}
						player[num].letters[len - 1] = NULL;
						PrintPlayer(num);
						Active(x, y);
					}
				}
				else{
					x_prev = x;//prevx
					y_prev = y;
					x_w[prev_num] = x;
					y_w[prev_num] = y;
					word[prev_num] = board[y][x];
					prev_num++;
					gotoxy(x * 3, y);
					SetConsoleTextAttribute(hStdOut, gray);
					cout << " " << board[y][x] << " ";
				}
			}
			break;
		}
		case 32: {//space
		
			int len = strlen(player[num].letters);
			if (len == 7) {
				len = 0;
			}
			for (int i = len; i < 7; i++) {
				player[num].letters[i] = (char)(rand() % 26 + 'A');
			}
			if (first) {
				bool ind = 0;
				for (int i = 0; i < esc_num; i++) {
					if (esc_y[i] == 7 && esc_x[i] == 7) {
						ind = 1;
					}
				}
				if (ind) {
					first = false;
					PrintPlayer(num);
				}
				else {
					if (prev_num > 0) {
						strcpy_s(player[num].letters, temp);
						for (int i = 0; i < esc_num; i++) {
							board[esc_y[i]][esc_x[i]] = ' ';
						}
						esc_num = 0;
						prev_num = 0;
						PrintBoard();
						PrintPlayer(num);
						break;
					}
				}
			}
			int ind = 1;
			word[prev_num] = NULL;
			if (prev_num > 0) {
				ind = 0;
				char wr[20];
				for (int i = 0; i < prev_num; i++) {
					wr[i] = word[i] + 32;
				}
				wr[prev_num] = NULL;
				if (Test(wr) >= 0) {
					ind = 1;
				}
				else {
					char ind_add;
					char s[50] = "                               ";
					SetConsoleTextAttribute(hStdOut, green);
					gotoxy(2, 19);
					cout << s;
					gotoxy(2, 20);
					cout << s;
					gotoxy(4, 19);
					cout << "No words in the dictionary.";
					gotoxy(4, 20);
					if (mode_of_game == 'e')
					{
						cout << "Add new word(" << wr << ")? Y/N ";
						cin >> ind_add;
						if (ind_add == 'Y' || ind_add == 'y') {
							AddWord(wr);
							ind = 1;
						}
					}
					else
					{
						int a = 0;
						while (!_kbhit());
						cout << "Press Enter to continue";
						while (a!=13)
						{
							
						 a = _getch();
				
						}
					}
					SetConsoleTextAttribute(hStdOut, def);
					gotoxy(2, 19);
					cout << s;
					gotoxy(2, 20);
					cout << s;

				}
			}
			if (ind) {
				strcpy_s(player[num].words[player[num].num_words], word);
				player[num].num_words++;
				player[num].score += ScoreWord();

				PrintScore();
				num = abs(num - 1);
				strcpy_s(temp, player[num].letters);
				esc_num = 0;
				prev_num = 0;
				PrintPlayer(num);
			}
			else {
				strcpy_s(player[num].letters, temp);
				for (int i = 0; i < esc_num; i++) {
					board[esc_y[i]][esc_x[i]] = ' ';
				}
				esc_num = 0;
				prev_num = 0;
				PrintBoard();
				PrintPlayer(num);
			}

			break;
		}
		case 27: {//esc
			strcpy_s(player[num].letters, temp);
			for (int i = 0; i < esc_num; i++) {
				board[esc_y[i]][esc_x[i]] = ' ';
			}
			esc_num = 0;
			prev_num = 0;
			PrintBoard();
			PrintPlayer(num);
			break;
		}
		case 48://exit
		{
			exit(0);
			break;
		}
		case 57://restart
		{
			
			char ind_add;
			char s[50] = "                               ";
			SetConsoleTextAttribute(hStdOut, green);
			gotoxy(4, 19);
			cout << s;
			gotoxy(4, 19);
			cout << "Do you want to restart game?";
			gotoxy(4, 20);
			cout << s;
			gotoxy(4, 20);
			cout << "Enter 'Y' for restart game: ";
			cin >> ind_add;
			if (ind_add == 'Y'|| ind_add=='y')
			{
				system("cls");
				StartGame();
				Game();
				x = 0; 
				y = 0;
				num = 0;
				x_prev = 0;
				y_prev = 0;
				y_neww = 0;
				x_neww = 0;
				x_word = 0;
				y_word = 0;
				first = true;
				esc_num = 0;
			}
			else
			{
				SetConsoleTextAttribute(hStdOut, def);
				gotoxy(4, 19);
				cout << s;
				gotoxy(4, 20);
				cout << s;
			}
			gotoxy(x, y);
			break;
		}
		case 49: {//descript of word
			meaning_of_word();
			break;
		}

		}

	}
	}