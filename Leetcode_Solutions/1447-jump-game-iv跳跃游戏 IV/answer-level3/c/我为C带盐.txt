### 解题思路
- 与各位大佬思路类似，先预处理，消除中间重复的数字，然后BFS；
- 但是怎么找到相同数字的最大边界和最小边界呢？C没有map，只能曲线救国；
- 先将val与index进行映射，然后按照val进行排序，然后通过二分找上下界，类似于C++的lower_bound()和upper_bound()；

### 代码

```c
#include <limits.h>
#include <stdio.h>
#define MAX_LEN 50001
#define MIN(a, b) ((a) < (b)? (a) : (b))

struct JumpNode {
	int val; 
	int index;
};

struct JumpQueue {
	int val;
	int pos;
	int lev;
};

static bool *g_visited;

static int Comp(void *a, void *b) 
{
	struct JumpNode *pa = (struct JumpNode *)a;
	struct JumpNode *pb = (struct JumpNode *)b;
	
	if (pa->val == pb->val) {
		return pa->index - pb->index;	
	}
	return pa->val - pb->val;
}

static bool FindNumLowIndex(struct JumpNode *nodes, int len, int tar, int *outIndex)
{
	int left, right, mid;
	left = 0; 
	right = len; 

	while (left < right) {
		mid = (left + right) / 2;
		if (nodes[mid].val >= tar) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	if (nodes[left].val == tar) {
		*outIndex = left;
		return true;
	}
	return false;
}

static bool FindNumUpIndex(struct JumpNode *nodes, int len, int tar, int *outIndex)
{
	int left, right, mid;
	left = 0; 
	right = len; 

	while (left < right) {
		mid = (left + right) / 2;
		if (nodes[mid].val > tar) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}

	if (left > len || left == 0) {
		return false;
	}

	if (nodes[left - 1].val == tar) {
		*outIndex = left - 1;
		return true;
	}
	return false;
}

/* 每次跳跃有三个方向 */
int Bfs(int* arr, struct JumpNode *nodes, int len)
{	
	struct JumpQueue *queue = (struct JumpQueue *)calloc(1, sizeof(struct JumpQueue) * (len + 1));
	int front, rear, curVal, curLev, curPos, nextPos, k, begin, end, j;
	struct JumpQueue *p;

	front = 0;
	rear = 0;

	queue[rear].lev = 0;
	queue[rear].pos = 0;
	queue[rear].val = arr[0];
	g_visited[0] = true;
	rear++;

	while (front != rear) {
		p = &queue[front];
		curLev = p->lev;
		curVal = p->val;
		curPos = p->pos;
		front++;

		if (curPos == len - 1) {
			return curLev;
		}

		/* 先尝试找相同的、最远的 */
		if (FindNumLowIndex(nodes, len, arr[curPos], &begin) && 
			FindNumUpIndex(nodes, len, arr[curPos], &end)) {
				for (j = end; j >= begin; j--) {
					if (g_visited[nodes[j].index] == true) {
						continue;
					}
					queue[rear].lev = curLev + 1;
					queue[rear].pos = nodes[j].index;
					queue[rear].val = nodes[j].val;
					g_visited[nodes[j].index] = true;
					rear++;
				}
		}
		for (k = 0; k < 2; k++) {
			if (k == 0) {
				nextPos = curPos + 1;
			} else {
				nextPos = curPos - 1;			
			}
			if (nextPos >= len || nextPos < 0) {
				continue;
			}
			if (g_visited[nextPos] == true) {
				continue;
			}
			queue[rear].lev = curLev + 1;
			queue[rear].pos = nextPos;
			queue[rear].val = arr[nextPos];
			g_visited[nextPos] = true;
			rear++;
		}
	}
	return -1;
}


int minJumps(int* arr, int arrSize)
{
	struct JumpNode *nodes = (struct JumpNode *)calloc(1, sizeof(struct JumpNode) * arrSize);
	int *tmpArr = (int *)calloc(1, sizeof(int) * arrSize);
	int i = 0;
	int outIndex, ans, tmp, tmpArrIndex;

	g_visited = (bool *)calloc(1, sizeof(bool) * MAX_LEN);

	tmp = arr[0];
	tmpArr[0] = tmp;
	tmpArrIndex = 1;

	for (i = 1; i < arrSize; i++) {
		if (arr[i] == tmp) {
			if (i == arrSize - 1) {
				tmpArr[tmpArrIndex++] = arr[i];
			} else if (arr[i + 1] != tmp) {
				tmpArr[tmpArrIndex++] = arr[i];
			} else {
				continue;
			}
		} else {
			tmpArr[tmpArrIndex++] = arr[i];
		}
		tmp = arr[i];
	}

	for (i = 0; i < tmpArrIndex; i++) {
		nodes[i].index = i;
		nodes[i].val = tmpArr[i];
	}

	qsort(nodes, tmpArrIndex, sizeof(struct JumpNode), Comp);
	ans = Bfs(tmpArr, nodes, tmpArrIndex);
	free(nodes);
	free(g_visited);
	free(tmpArr);
	return ans;
}
```