### 解题思路
此题数据结构有点儿复杂，先建立统一的数据模型，再进行逻辑编写。这样也方便问题跟踪，见traceAllNum（辅助定位）
还有一个关键点，就是回溯的对象。一般这种题目，都是以矩阵作为回溯的对象。
此题目也可以用其他的回溯对象，但是性能会降低。

![image.png](https://pic.leetcode-cn.com/4b399d7fe0e408acf08123b5cd3a9bc6eea613ac7c27656770ef9492ffe1460b-image.png)

### 代码

```c
#define MY_NUM_3 3
#define MY_NUM_9 9
#define MY_INVALID (-1)

#define MY_EXIST 1
#define MY_NONE 0

typedef struct {
	int x;
	int y;
} MyPos;

typedef struct {
	int num;
	int row[MY_NUM_9];
	int col[MY_NUM_9];
	int square[MY_NUM_9];
	MyPos pos[MY_NUM_9];
	int posCnt;
} MyNumMap;

typedef struct {
	MyNumMap nums[MY_NUM_9];
	int map[MY_NUM_9][MY_NUM_9];
	
	char **board;
	int boardSize;
	int *boardColSize;
} MyStatus;

int transNum(char ch)
{
	if (ch < '1' || ch > '9') {
		return MY_INVALID;
	}
	return ch - '1';
}
int transSqure(int row, int col)
{
	return (row / MY_NUM_3) * MY_NUM_3 + (col / MY_NUM_3);
}
void sNumMapAddPos(MyNumMap *curNumMap, int x, int y)
{
	if (curNumMap->posCnt == MY_NUM_9) {
		printf("sNumMapAddPos err\n");
		return;
	}
	curNumMap->pos[curNumMap->posCnt].x = x;
	curNumMap->pos[curNumMap->posCnt].y = y;
	curNumMap->posCnt++;
	return;
}
void sNumMapDelPos(MyNumMap *curNumMap)
{
	if (curNumMap->posCnt == 0) {
		printf("sNumMapDelPos err\n");
		return;
	}
	curNumMap->posCnt--;
	return;
}
void sProcMap(MyStatus *s, char** board, int boardSize, int* boardColSize)
{
	int i, j;
	int numInx, squareInx;
	MyNumMap *curNumMap = NULL;
	memset(s, 0x00, sizeof(MyStatus));
	for (i = 0; i < MY_NUM_9; i++) {
		s->nums[i].num = i + 1;
	}
	s->board = board;
	s->boardSize = boardSize;
	s->boardColSize = boardColSize;
	for (i = 0; i < MY_NUM_9; i++) {
		for (j = 0; j < MY_NUM_9; j++) {
			numInx = transNum(board[i][j]);
			if (numInx == MY_INVALID) {
				continue;
			}
			s->map[i][j] = MY_EXIST;
			curNumMap = &(s->nums[numInx]);
			sNumMapAddPos(curNumMap, i, j);
			curNumMap->row[i] = MY_EXIST;
			curNumMap->col[j] = MY_EXIST;
			squareInx = transSqure(i, j);
			curNumMap->square[squareInx] = MY_EXIST;
		}
	}
	return;
}
void traceNum(MyNumMap *curNumMap)
{
	int i;
	printf("num:%d, posCnt = %d : ", curNumMap->num, curNumMap->posCnt);
	for (i = 0; i < curNumMap->posCnt; i++) {
		printf("[%d,%d],", curNumMap->pos[i].x, curNumMap->pos[i].y);
	}
	printf("\n");
}
void traceAllNum(MyStatus *s)
{
	int i;
	for (i = 0; i < MY_NUM_9; i++) {
		traceNum(&s->nums[i]);
	}
}
void sProcBoard(MyStatus *s)
{
	int i, j;
	int x, y;
	MyNumMap *curNumMap = NULL;
	for (i = 0; i < MY_NUM_9; i++) {
		curNumMap = &(s->nums[i]);
		for (j = 0; j < curNumMap->posCnt; j++) {
			x = curNumMap->pos[j].x;
			y = curNumMap->pos[j].y;
			s->board[x][y] = curNumMap->num + '0';
		}
	}
	return;
}

int proc(MyStatus *s, int x, int y)
{
	int ret;
	int i, squareInx;
	int next_x, next_y;
	next_x = x + (y + 1) / MY_NUM_9 - y / MY_NUM_9; 
	next_y = (y + 1) % MY_NUM_9;
	if (s->map[x][y] == MY_EXIST) {
		if (next_x == MY_NUM_9) {
			return 1; /* 有解 */
		}
		return proc(s, next_x, next_y);
	}
	for (i = 0; i < MY_NUM_9; i++) {
		squareInx = transSqure(x, y);
		if (s->nums[i].row[x] == MY_EXIST ||
			s->nums[i].col[y] == MY_EXIST || 
			s->nums[i].square[squareInx] == MY_EXIST) {
			continue;
		}
		s->nums[i].row[x] = MY_EXIST;
		s->nums[i].col[y] = MY_EXIST;
		s->nums[i].square[squareInx] = MY_EXIST;
		s->map[x][y] = MY_EXIST;
		sNumMapAddPos(&s->nums[i], x, y);
		if (next_x == MY_NUM_9) {
			return 1; /* 有解 */
		}
		ret = proc(s, next_x, next_y);
		if (ret == 1) {
			return 1;
		}
		s->nums[i].row[x] = MY_NONE;
		s->nums[i].col[y] = MY_NONE;
		s->nums[i].square[squareInx] = MY_NONE;
		s->map[x][y] = MY_NONE;
		sNumMapDelPos(&s->nums[i]);
	}
	return 0;
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
	MyStatus s;
	int numInx;
	sProcMap(&s, board, boardSize, boardColSize);
	//traceAllNum(&s);
	proc(&s, 0, 0);
	sProcBoard(&s);
	//traceAllNum(&s);
	return;
}
```