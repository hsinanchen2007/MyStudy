
注意：
1. 访问过的节点不能再访问
2. 不能走回头路
```
#define MAXSIZE 900
int holeX;
int holeY;
char bestWay[MAXSIZE]; 
int bestStepCnt;
char curWay[MAXSIZE];
const char action[4] = { 'd', 'l', 'r', 'u' };

void moveNextPos(int** maze, int mazeSize, int* mazeColSize, int curX, int curY, int curStepCnt, int index, char lastMove) {
	if (curStepCnt > bestStepCnt) {
		return;
	} else if (curStepCnt == bestStepCnt) {
		if ((curX == holeX && curY == holeY) && (strcmp(curWay, bestWay) < 0)) {
			memset(bestWay, 0, sizeof(char) * MAXSIZE);
			strcpy(bestWay, curWay);
		}
		return;
	} 
	
	if (curX == holeX && curY == holeY) {
		memset(bestWay, 0, sizeof(char) * MAXSIZE);
		strcpy(bestWay, curWay);
		bestStepCnt = curStepCnt;
		return;
	}

	maze[curX][curY] = 2;
	for (int k = 0; k < 4; k++) {
		if (lastMove != action[3 - k]) {
			int stepToMove = 0;
			int XToMove = 0;
			int YToMove = 0;
			if (action[k] == 'd') {
				for (int i = 1; i < mazeSize - curX; i++) {
					if (maze[curX + i][curY] == 1) {
						stepToMove = i - 1;
						break;
					}
					if (curX + i == holeX && curY == holeY) {
						stepToMove = i;
						break;
					}
					stepToMove = i;
				}
				XToMove += stepToMove;
			} else if (action[k] == 'l') {
				for (int i = 1; i <= curY; i++) {
					if (maze[curX][curY - i] == 1) {
						stepToMove = i - 1;
						break;
					}
					if (curX == holeX && curY - i == holeY) {
						stepToMove = i;
						break;
					}
					stepToMove = i;
				}
				YToMove -= stepToMove;
			} else if (action[k] == 'r') {
				for (int i = 1; i < mazeColSize[curX] - curY; i++) {
					if (maze[curX][curY + i] == 1) {
						stepToMove = i - 1;
						break;
					}
					if (curX == holeX && curY + i == holeY) {
						stepToMove = i;
						break;
					}
					stepToMove = i;
				}
				YToMove += stepToMove;
			} else if (action[k] == 'u') {
				for (int i = 1; i <= curX; i++) {
					if (maze[curX - i][curY] == 1) {
						stepToMove = i - 1;
						break;
					}
					if (curX - i == holeX && curY == holeY) {
						stepToMove = i;
						break;
					}
					stepToMove = i;
				}
				XToMove -= stepToMove;
			}

			if (stepToMove == 0 || maze[curX + XToMove][curY + YToMove] == 2) {
				continue;
			}

			curWay[index] = action[k];
			moveNextPos(maze, mazeSize, mazeColSize, curX + XToMove, curY + YToMove, curStepCnt + stepToMove, index + 1, action[k]);
			curWay[index] = '\0';
		}
	}
	maze[curX][curY] = 0;
	return;
}

char *findShortestWay(int** maze, int mazeSize, int* mazeColSize, int* ball, int ballSize, int* hole, int holeSize) {
	bestStepCnt = MAXSIZE;
	memset(bestWay, 0, sizeof(char) * MAXSIZE);
	memset(curWay, 0, sizeof(char) * MAXSIZE);
	int curX = ball[0];
	int curY = ball[1];
	holeX = hole[0];
	holeY = hole[1];

	maze[curX][curY] = 2;
	moveNextPos(maze, mazeSize, mazeColSize, curX, curY, 0, 0, '\0');
	maze[curX][curY] = 0;
	if (bestStepCnt == MAXSIZE) {
		strcpy(bestWay, "impossible");
	}
	return bestWay;
}
```


