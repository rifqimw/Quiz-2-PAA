#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;

char board[30][30];
int isVisited[30][30];
int size;
queue <pair <int, int> > Queue;

void BFS(int x, int y) {
	pair <int,int> coord = make_pair(x,y);
	Queue.push(coord);
	
	while(!Queue.empty()) {
		coord = Queue.front();
		if(isVisited[coord.first][coord.second] || board[coord.first][coord.second]=='X') {
			Queue.pop();
			continue;
		}
		int counter = 0; char tempcount;
		
		if(board[coord.first][coord.second-1]=='X') counter+=1; 
		if(board[coord.first-1][coord.second-1]=='X') counter+=1; 
		if(board[coord.first-1][coord.second]=='X') counter+=1; 
		if(board[coord.first-1][coord.second+1]=='X') counter+=1; 
		if(board[coord.first][coord.second+1]=='X') counter+=1; 
		if(board[coord.first+1][coord.second+1]=='X') counter+=1; 
		if(board[coord.first+1][coord.second]=='X') counter+=1; 
		if(board[coord.first+1][coord.second-1]=='X') counter+=1; 
		
		if(counter>0) {
			board[coord.first][coord.second] = (char)counter;
		} else {
			board[coord.first][coord.second] = '.';
		}
		
		if(!isVisited[coord.first][coord.second-1] && board[coord.first][coord.second-1]!='X') Queue.push(make_pair(coord.first,coord.second-1));
		if(!isVisited[coord.first-1][coord.second-1] && board[coord.first-1][coord.second-1]!='X') Queue.push(make_pair(coord.first-1,coord.second-1));
		if(!isVisited[coord.first-1][coord.second] && board[coord.first-1][coord.second]!='X') Queue.push(make_pair(coord.first-1,coord.second));
		if(!isVisited[coord.first-1][coord.second+1] && board[coord.first-1][coord.second+1]!='X' ) Queue.push(make_pair(coord.first-1,coord.second+1));
		if(!isVisited[coord.first][coord.second+1] && board[coord.first][coord.second+1]!='X') Queue.push(make_pair(coord.first,coord.second+1));
		if(!isVisited[coord.first+1][coord.second+1] && board[coord.first+1][coord.second+1]!='X') Queue.push(make_pair(coord.first+1,coord.second+1));
		if(!isVisited[coord.first+1][coord.second] && board[coord.first+1][coord.second]!='X') Queue.push(make_pair(coord.first+1,coord.second));
		if(!isVisited[coord.first+1][coord.second-1] && board[coord.first+1][coord.second-1]!='X' ) Queue.push(make_pair(coord.first+1,coord.second-1));
		
		isVisited[coord.first][coord.second] = 1;
		Queue.pop();
	}
}

bool isFinished() {
	int status=0;
	for(int i=0; i<size; i++) for(int j=0; j<size; j++) if(board[i][j]=='o') status-=1;
	if(status==0) return 1;
	else return 0;
}

void doMineSweep() {
	int x, y;
	print();
	while(true) {		
		if(isFinished()) {
			printf("You win ?\n");
			return;
		}
		printf("Mau mencoba klik di koordinat (x,y) yang mana? : ");
		scanf("%d %d", &x, &y);
		if(board[x][y]=='X') {
			printf("You lose!\n");
			return;
		}
		BFS(x, y);
		if(!isFinished())print();
	}	
}

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
	doMineSweep();
	return 0;
}
