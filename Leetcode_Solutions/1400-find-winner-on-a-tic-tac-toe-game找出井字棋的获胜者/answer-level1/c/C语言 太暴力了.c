### 解题思路
性能一般，就是暴力...

### 代码

```c
#define MAP_SIZE 3
#define A_SETP	1
#define B_STEP	(-1)
#define A_WIN	3
#define B_WIN	(-3)

bool checkRowRlt(int loc[MAP_SIZE][MAP_SIZE], int size, int expect)
{
	int i, j;
	int rlt;
	for (i = 0; i < size; i++) {
		rlt = 0;
		for (j = 0; j < size; j++) {
			rlt += loc[i][j];
		}
		if (rlt == expect) {
			return true;
		}
	}
	return false;
}

bool checkColRlt(int loc[MAP_SIZE][MAP_SIZE], int size, int expect)
{
	int i, j;
	int rlt;
	for (i = 0; i < size; i++) {
		rlt = 0;
		for (j = 0; j < size; j++) {
			rlt += loc[j][i];
		}
		if (rlt == expect) {
			return true;
		}
	}
	return false;
}

bool checkOtherRlt(int loc[MAP_SIZE][MAP_SIZE], int size, int expect)
{
	int i, j;
	int rlt0, rlt1;
	rlt0 = 0;
	rlt1 = 0;
	for (i = 0; i < size; i++) {
		rlt0 += loc[i][i];
		rlt1 += loc[size - 1 - i][i];
	}
	if (rlt0 == expect || rlt1 == expect) {
		return true;
	}
	return false;
}

char * tictactoe(int** moves, int movesSize, int* movesColSize){
	int i;
	int locA[MAP_SIZE][MAP_SIZE] = { 0 };
	int locB[MAP_SIZE][MAP_SIZE] = { 0 };
	bool rltA, rltB;
	for (i = 0; i < movesSize; i += 2) {
		locA[moves[i][0]][moves[i][1]] = A_SETP;
	}
	for (i = 1; i < movesSize; i += 2) {
		locB[moves[i][0]][moves[i][1]] = B_STEP;
	}
	rltA = checkRowRlt(locA, MAP_SIZE, A_WIN) || checkColRlt(locA, MAP_SIZE, A_WIN) || checkOtherRlt(locA, MAP_SIZE, A_WIN);
	if (rltA) {
		return "A";
	}
	rltB = checkRowRlt(locB, MAP_SIZE, B_WIN) || checkColRlt(locB, MAP_SIZE, B_WIN) || checkOtherRlt(locB, MAP_SIZE, B_WIN);
	if (rltB) {
		return "B";
	}
	return movesSize < (MAP_SIZE * MAP_SIZE) ? "Pending" : "Draw";
}
```