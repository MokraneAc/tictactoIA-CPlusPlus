#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct Move
{
	int row, col;
};
char player = 'X', opponent = 'O';
bool isMovesLeft(char board[3][3])
{
	for (int i = 0; i<3; i++)
		for (int j = 0; j<3; j++)
			if (board[i][j]=='_')
				return true;
	return false;
}

int evaluate(char b[3][3])
{
	for (int row = 0; row<3; row++)
	{
		if (b[row][0]==b[row][1] &&
			b[row][1]==b[row][2])
		{
			if (b[row][0]==player)
				return +10;
			else if (b[row][0]==opponent)
				return -10;
		}
	}
	for (int col = 0; col<3; col++)
	{
		if (b[0][col]==b[1][col] &&
			b[1][col]==b[2][col])
		{
			if (b[0][col]==player)
				return +10;

			else if (b[0][col]==opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
	{
		if (b[0][0]==player)
			return +10;
		else if (b[0][0]==opponent)
			return -10;
	}

	if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
	{
		if (b[0][2]==player)
			return +10;
		else if (b[0][2]==opponent)
			return -10;
	}

	return 0;
}

int minimax(char board[3][3], int depth, bool isMax)
{
	int score = evaluate(board);

	if (score == 10)
		return score;

	if (score == -10)
		return score;

	if (isMovesLeft(board)==false)
		return 0;

	if (isMax)
	{
		int best = -1000;

		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{

				if (board[i][j]=='_')
				{

					board[i][j] = player;

					best = max( best,
						minimax(board, depth+1, !isMax) );


					board[i][j] = '_';
				}
			}
		}
		return best;
	}


	else
	{
		int best = 1000;


		for (int i = 0; i<3; i++)
		{
			for (int j = 0; j<3; j++)
			{

				if (board[i][j]=='_')
				{

					board[i][j] = opponent;


					best = min(best,
						minimax(board, depth+1, !isMax));

					board[i][j] = '_';
				}
			}
		}
		return best;
	}
}

Move findBestMove(char board[3][3])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;


	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
		{

			if (board[i][j]=='_')
			{

				board[i][j] = player;


				int moveVal = minimax(board, 0, false);

				board[i][j] = '_';


				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}



	return bestMove;
}

char human_turn(char board[3][3], char h)
{int a;

	char human = h;
	cout <<"Where do you want to put your Sign " <<" " ;
	cin>> a;
	if(a == 1) {
		board[0][0] = human;}
	 else if( a==2 ) {
		board[0][1] = human;}
	else if( a==3 ) {
		board[0][2] = human;}
	else if( a==4 ) {
		board[1][0] = human;}
	else if( a==5 ) {
		board[1][1] = human;}
	else if( a==6 ) {
		board[1][2] = human;}
	else if( a==7 ) {
		board[2][0] = human;}
	else if( a==8 ) {
		board[2][1] = human;}
	else if( a==9 ) {
		board[2][2] = human;}
}


int main()
{
	char board[3][3] =
	{
		{ '_', '_', '_' },
		{ '_', '_', '_' },
		{ '_', '_', '_' }
	};
  int sign;
  char h;
  char c;
  printf("choose your sign press / 1 for X / 0 for O: ");
  cin >> sign;
  if (sign == 1){
    h = 'X';
    c = 'O';
    player  = 'O';
    opponent= 'X';
  }
  else if (sign == 0){
    h = 'O';
    c = 'X';
    opponent= 'X';
    player  = 'O';
  }
  system("clear");
	int mode;
	printf("Choose Wich one goes first 1 for computer 0 for human: ");
	cin >> mode ;
  system("clear");
	if (mode == 0){
	while (1){

    if (evaluate(board) == 10){
      printf( "%c wins ",player);
      break;
    }
    if (evaluate(board) == -10){
      printf("%c wins " ,opponent);
      break;
    }
    if (isMovesLeft(board) == false){
      printf("Tie");
      break;
    }
		for ( int i = 0; i < 3; i++ ){
					for (int j = 0; j < 3; j++){
								cout<< board[i][j] << " ";
								  }
							    	cout << endl;
								}

human_turn(board,h);
	system("clear");
		for ( int i = 0; i < 3; i++ ){
					for (int j = 0; j < 3; j++){
								cout<< board[i][j] << " ";
								  }
							    	cout << endl;
								}
system("clear");
if (evaluate(board) == 10){
  printf( "%c wins ",player);
  break;
}
if (evaluate(board) == -10){
  printf("%c wins " ,opponent);
  break;
}
if (isMovesLeft(board) == false){
  printf("Tie");
  break;
}


	Move bestMove = findBestMove(board);
	board[bestMove.row][bestMove.col] = c;
		for ( int i = 0; i < 3; i++ ){
					for (int j = 0; j < 3; j++){
								cout<< board[i][j] << " ";
								  }
							    	cout << endl;
								}
								system("clear");
}}
else if (mode == 1){
	while (1){

    if (evaluate(board) == 10){
      printf( "%c wins ",player);
      break;
    }
    if (evaluate(board) == -10){
      printf("%c wins " ,opponent);
      break;
    }
    if (isMovesLeft(board) == false){
      printf("Tie");
      break;
    }

Move bestMove = findBestMove(board);
board[bestMove.row][bestMove.col] = c;
		for ( int i = 0; i < 3; i++ ){
					for (int j = 0; j < 3; j++){
								cout<< board[i][j] << " ";
								  }
							    	cout << endl;
								}

if (evaluate(board) == 10){
  printf( "%c wins ",player);
  break;
}
if (evaluate(board) == -10){
  printf("%c wins " ,opponent);
  break;
}
if (isMovesLeft(board) == false){
  printf("Tie");
  break;
}


human_turn(board,h);
		for ( int i = 0; i < 3; i++ ){
					for (int j = 0; j < 3; j++){
								cout<< board[i][j] << " ";
								  }
							    	cout << endl;
								}
								system("clear");
}
}
	return 0;
}

