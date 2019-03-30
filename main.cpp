#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

char board[30][30];
int isVisited[30][30];
int size;
queue <pair <int, int> > Queue;


int main() {
   int mines; 
	printf("MINESWEEPER SEDERHANA\nInput nilai n untuk papan ukuran n x n yang diinginkan (maks 30): ");
	scanf("%d", &size);
	printf("Mau berapa mines (ranjau)? : ");
	scanf("%d", &mines);
	queue <pair <int,int> > minePost;
	while(mines--) {
		pair <int,int> minesLoc;
		minesLoc.first = rand() % size;
		minesLoc.second = rand() % size;
		minePost.push(minesLoc);
	}	
	for(int i=0; i<size; i++) for(int j=0; j<size; j++) { board[i][j] = 'o'; isVisited[i][j] = 0; }
	while(!minePost.empty()) {
		board[minePost.front().first][minePost.front().second] = 'X';
		minePost.pop();
	}
	
	return 0;
}
