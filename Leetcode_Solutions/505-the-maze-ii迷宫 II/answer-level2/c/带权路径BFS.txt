### 解题思路
与普通BFS不一样的是，路径是有权值的，最先到达终点的点，不一定是最短距离

### 代码

```c
#include <stdio.h>
#include <limits.h>

#define DIRECT 4
#define MAX_QUEUE_SIZE 10001
#define MAX_N 128
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int **g_matrix;
static int g_m, g_n;
static int g_iGo[] = {-1, 0, 1, 0};
static int g_jGo[] = {0, 1, 0, -1};
static int g_visited[MAX_N][MAX_N];

static bool IsValid(int i, int j)
{
	if (i < 0 || i >= g_m ||
		j < 0 || j >= g_n) {
		return false;
	}
	return true;
}

static int GetNext(int i, int j, int direct, int *a, int *b)
{
	int nextI, nextJ;
	int len = 0;

	nextI = i + g_iGo[direct];
	nextJ = j + g_jGo[direct];
	while (IsValid(nextI, nextJ) && g_matrix[nextI][nextJ] == 0) {
		nextI = nextI + g_iGo[direct];
		nextJ = nextJ + g_jGo[direct];        
		len++;
	}
	*a = nextI - g_iGo[direct];
	*b = nextJ - g_jGo[direct];
	return len;
} 

struct QNode {
	int i, j;
};

static struct QNode g_queue[MAX_QUEUE_SIZE];

static void Update(int *n)
{
	*n = (*n + 1) % MAX_QUEUE_SIZE;
}

static int Bfs(int i, int j, int tarI, int tarJ)
{
	int front, rear, curI, curJ, nextI, nextJ, k, len;

	front = 0;
	rear = 0;
	g_queue[rear].i = i;
	g_queue[rear].j = j;
	g_visited[i][j] = 0;
	Update(&rear);

	while (front != rear) {
		curI = g_queue[front].i;
		curJ = g_queue[front].j;
		Update(&front);

		for (k = 0; k < DIRECT; k++) {
			/* 走到这个方向最远的地方 */
			len = GetNext(curI, curJ, k, &nextI, &nextJ);
			if (g_visited[nextI][nextJ] <= g_visited[curI][curJ] + len) {
				continue;
			}
			g_queue[rear].i = nextI;
			g_queue[rear].j = nextJ;
			g_visited[nextI][nextJ] = g_visited[curI][curJ] + len;
			Update(&rear);
		}
	}
	return g_visited[tarI][tarJ] == INT_MAX ? -1 : g_visited[tarI][tarJ];
}

int shortestDistance(int** maze, int mazeSize, int* mazeColSize, 
					 int* start, int startSize, int* destination, int destinationSize){
	int i, j;

	g_matrix = maze;
	g_m = mazeSize;
	g_n = *mazeColSize;

	for (i = 0; i < MAX_N; i++) {
		for (j = 0; j < MAX_N; j++) {
			g_visited[i][j] = INT_MAX;
		}
	}

	return Bfs(start[0], start[1], destination[0], destination[1]);
}
```