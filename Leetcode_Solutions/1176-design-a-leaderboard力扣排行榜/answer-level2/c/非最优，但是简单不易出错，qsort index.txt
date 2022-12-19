### 解题思路
非最优，但是简单不易出错，qsort index

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE  10002

struct node {
	int id;
	int score;
	int valid;
};

typedef struct {
	int data;
} Leaderboard;

static struct node array[MAX_NODE];
static int index_array[MAX_NODE];
static Leaderboard board;

Leaderboard *leaderboardCreate()
{
	int loop;
	memset(array, 0, sizeof(array));
	for (loop = 0; loop < MAX_NODE; loop++) {
		index_array[loop] = loop;
	}
	return &board;
}

void leaderboardAddScore(Leaderboard *obj, int playerId, int score)
{
	array[playerId].score += score;
}

int compare(const void *p1, const void *p2)
{
	int index1 = *(const int *)p1;
	int index2 = *(const int *)p2;
	return array[index2].score - array[index1].score;
}

int leaderboardTop(Leaderboard *obj, int K)
{
	int loop;
	int sum = 0;
	qsort(index_array, MAX_NODE, sizeof(int), compare);
	for (loop = 0; loop < K; loop++) {
		sum += array[index_array[loop]].score;
	}
    return sum;
}

void leaderboardReset(Leaderboard *obj, int playerId)
{
	array[playerId].score = 0;
}

void leaderboardFree(Leaderboard *obj)
{
	return;
}
```