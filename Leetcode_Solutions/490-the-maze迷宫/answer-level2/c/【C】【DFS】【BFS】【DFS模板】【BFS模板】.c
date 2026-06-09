提供两种解题方法，两种模板，各位参考；
C语言写队列比较麻烦，代码量较大

- - DFS实现方法
 ```
#include <stdio.h>
#define DIRECT 4
#define MAX_N 128
static int **matrix;
static int m, n;
static int iGo[] = {-1, 0, 1, 0};
static int jGo[] = {0, 1, 0, -1};
static int visited[MAX_N][MAX_N];

static bool IsValid(int i, int j)
{
	if (i < 0 || i >= m ||
		j < 0 || j >= n) {
			return false;
	}
	return true;
}

static bool IsNextOk(int i, int j, int direct)
{
	int nextI, nextJ;
	nextI = i + iGo[direct];
	nextJ = j + jGo[direct];
	if (!IsValid(nextI, nextJ)) {
		return true;
	}
	if (matrix[nextI][nextJ] == 1) {
		return true;
	}

	return false;
}

void GetNext(int i, int j, int direct, int *a, int *b)
{
	int nextI, nextJ;
	nextI = i + iGo[direct];
	nextJ = j + jGo[direct];
	while (IsValid(nextI, nextJ) && matrix[nextI][nextJ] == 0) {
		nextI = nextI + iGo[direct];
		nextJ = nextJ + jGo[direct];        
	}
	*a = nextI - iGo[direct];
	*b = nextJ - jGo[direct];
} 

static bool Dfs(int i, int j, int tarI, int tarJ, int direct)
{
	bool ret;
	int k;
	int nextI, nextJ;
	/* 并且在这个方向上有墙壁 */
	if (i == tarI && j == tarJ && IsNextOk(i, j, direct)) {
		return true;
	}

	if (!IsValid(i, j)) {
		return false;
	}

	if (matrix[i][j] == 1) {
		return false;
	}

	if (visited[i][j] == 1) {
		return false;
	}

	visited[i][j] = 1;
	for (k = 0; k < DIRECT; k++) {
		/* 走到这个方向最远的地方 */
		GetNext(i, j, k, &nextI, &nextJ);
		ret = Dfs(nextI, nextJ, tarI, tarJ, k);
		if (ret) {
			return true;
		}
	}
	return false;
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize)
{
	int i, j;
	matrix = maze;
	m = mazeSize;
	n = *mazeColSize;
	memset(visited, 0, sizeof(visited));

	return Dfs(start[0], start[1], 
		destination[0], destination[1], 0);
}
```
- BFS实现方法
```
#include <stdio.h>
#define DIRECT 4
#define MAX_N 128
#define QUEUE_LEN (MAX_N * MAX_N)
static int **matrix;
static int m, n;
static int iGo[] = {-1, 0, 1, 0};
static int jGo[] = {0, 1, 0, -1};
static int visited[MAX_N][MAX_N];

struct Node {
	int i;
	int j;
	int direct;
};

static struct Node queue[QUEUE_LEN];

static bool IsValid(int i, int j)
{
	if (i < 0 || i >= m ||
		j < 0 || j >= n) {
			return false;
	}
	return true;
}

static bool IsNextOk(int i, int j, int direct)
{
	int nextI, nextJ;
	nextI = i + iGo[direct];
	nextJ = j + jGo[direct];
	if (!IsValid(nextI, nextJ)) {
		return true;
	}
	if (matrix[nextI][nextJ] == 1) {
		return true;
	}

	return false;
}

void GetNext(int i, int j, int direct, int *a, int *b)
{
	int nextI, nextJ;
	nextI = i + iGo[direct];
	nextJ = j + jGo[direct];
	while (IsValid(nextI, nextJ) && matrix[nextI][nextJ] == 0) {
		nextI = nextI + iGo[direct];
		nextJ = nextJ + jGo[direct];        
	}
	*a = nextI - iGo[direct];
	*b = nextJ - jGo[direct];
} 

void Update(int *n)
{
	*n = (*n + 1) % QUEUE_LEN;
}

bool IsQueueFull(int front, int rear) 
{
	return (rear + 1) % QUEUE_LEN == front;
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize)
{
	int front, rear;
	struct Node *p;
	int curI, curJ, nextI, nextJ;
	int k;

	matrix = maze;
	m = mazeSize;
	n = *mazeColSize;
	memset(visited, 0, sizeof(visited));
	memset(queue, 0, sizeof(queue));
	front = 0;
	rear = 0;

	queue[rear].i = start[0];
	queue[rear].j = start[1];
	Update(&rear);
	visited[start[0]][start[1]] = 1;

	while (front != rear) {
		p = &queue[front];
		curI = p->i;
		curJ = p->j;
		Update(&front);
		if (curI == destination[0] && curJ == destination[1] && 
			IsNextOk(curI, curJ, p->direct)) {
			return true;
		}
		for (k = 0; k < DIRECT; k++) {
			GetNext(curI, curJ, k, &nextI, &nextJ);
			/* 走到最远的方向，没有被访问过 */
			if (visited[nextI][nextJ] == 0 && !IsQueueFull(front, rear)) {
				queue[rear].i = nextI;
				queue[rear].j = nextJ;
				queue[rear].direct = k;
				Update(&rear);                
				visited[nextI][nextJ] = 1;
			}
		}
	}

	return false;
}

```

BFS一般都比DFS快

- DFS矩阵类模板
```
#include <stdio.h>

/* 设置使用的全局变量，包括可以扩展的方向 */
#define DIRECT 4
static char **matrix;
static int m, n;
static char **visited;
static int iGo[DIRECT] = {-1, 0, 1, 0};
static int jGo[DIRECT] = {0, 1, 0, -1};

/* 判断下标是否合法 */
static bool IsValid(int i, int j)
{
	if (i < 0 || i >= m ||
		j < 0 || j >= n) {
			return false;
	}
	return true;
}

static bool Dfs(char *word, int pos, int i, int j)
{
	bool ret;
	int k;
	
	/* 1、先判断外界输入条件，因为有可能已经找到了，但是由于后边不合法，导致没有找到正确答案 */
	if (pos == strlen(word)) {
		return true;
	}
	/* 2、判断下标是否合法 */
	if (!IsValid(i, j)) {
		return false;
	}

	/* 3、结合矩阵进行一些判断，例如判断当前坐标是不是1或者0，是不是路障等 */
	if (matrix[i][j] != word[pos]) {
		return false;
	}

	/* 4、防止重复遍历 */
	if (visited[i][j] == 1) {
		return false;
	}
	visited[i][j] = 1;

	/* 5、遍历各个方向 */
	for (k = 0; k < DIRECT; k++) {
		ret = Dfs(word, pos + 1, i + iGo[k], j + jGo[k]);
		/* 6、如果找到了则直接返回不会走到函数结束的return false处，是否已经访问过的标记也没有清除 */
		if (ret) {
			return true;
		}
	}
	/* 7、标记恢复 */
	visited[i][j] = 0;
	return false;
}
```

- BFS矩阵类模板

```
#include <stdio.h>
#define DIRECT 4
#define MAX_N 128
/* 队列一般定义为最大值，leetcode对于内存一般要求较低 */
#define QUEUE_LEN (MAX_N * MAX_N)
static int **matrix;
static int m, n;
static int iGo[] = {-1, 0, 1, 0};
static int jGo[] = {0, 1, 0, -1};
/* 如果是字符串类型的，就可以使用hash来查找是否访问过 */
static int visited[MAX_N][MAX_N];

/* 队列节点数据结构体，一般是一个横坐标，一个纵坐标，一个lev用来求最短路径，剩下的视情况而定 */
struct Node {
	int i;
	int j;
	int direct;
};

static struct Node queue[QUEUE_LEN];

static bool IsValid(int i, int j)
{
	if (i < 0 || i >= m ||
		j < 0 || j >= n) {
			return false;
	}
	return true;
}

static bool IsNextOk(int i, int j, int direct)
{
	/* 判断是否到达终点 */
	return true;
}

void GetNext(int i, int j, int direct, int *a, int *b)
{
	/* 获取下一个位置 */
} 

void Update(int *n)
{
	/* 循环队列指针的更新 */
	*n = (*n + 1) % QUEUE_LEN;
}

bool IsQueueFull(int front, int rear) 
{
	/* 判断循环队列是否满了，队列定义为最大可能的话，一般情况不会出现队列满，
	如果出现了说明代码bug */
	return (rear + 1) % QUEUE_LEN == front;
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize)
{
	int front, rear;
	struct Node *p;
	int curI, curJ, nextI, nextJ;
	int k;

	matrix = maze;
	m = mazeSize;
	n = *mazeColSize;
	memset(visited, 0, sizeof(visited));
	memset(queue, 0, sizeof(queue));
	front = 0;
	rear = 0;

	/* 加入初始第一个元素 */
	queue[rear].i = start[0];
	queue[rear].j = start[1];
	Update(&rear);
	visited[start[0]][start[1]] = 1;

	while (front != rear) {
		/* 出队 */
		p = &queue[front];
		curI = p->i;
		curJ = p->j;
		Update(&front);
		/* 判断出队元素是否到达了出口 */
		if (curI == destination[0] && curJ == destination[1] && 
			IsNextOk(curI, curJ, p->direct)) {
				return true;
		}
		/* 按照题意，将该节点的下一层全部入队 */
		for (k = 0; k < DIRECT; k++) {
			GetNext(curI, curJ, k, &nextI, &nextJ);

			/* 为避免重复访问，使用visited判断，并且判断这是是否队列满
			还有一种情况不是矩阵，为了提升是否访问过该节点，可以使用hash查找来确定是否访问过该节点
			*/
			if (visited[nextI][nextJ] == 0 && !IsQueueFull(front, rear)) {
				queue[rear].i = nextI;
				queue[rear].j = nextJ;
				queue[rear].direct = k;
				Update(&rear);                
				visited[nextI][nextJ] = 1;
			}
		}
	}

	return false;
}

```
