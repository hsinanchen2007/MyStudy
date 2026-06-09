正儿八经的拓扑排序


1. 统计各个点的入度，将入度为0的点入栈；
2. 遍历栈（栈不为空时循环）
- 输出栈顶元素，即排序后结果
- 对栈顶的邻接点k执行如下操作：
- 1、将定点k入度减1；
- 2、如果顶点k的入度是0，则入栈
1. 如果输出的顶点数与输入的顶点数相等，则无回路，拓扑排序结束；
2. 如果输出的顶点数小于输入的顶点数，则说明有回路；

```
#include <stdio.h>
#define MAX_N (1024 * 10)
struct Enode {
	int vIndex;
	struct Enode *next;
};

struct Vnode {
	int vectex;
	struct Enode *firstEdge;
};

struct Graph {
	int vNum;
	int eNum;
	struct Vnode nodes[MAX_N];
};

static struct Graph gGraph;

static void AddToEnd(struct Enode *firstEdge, struct Enode *newNode)
{
	struct Enode *p = firstEdge;

	while (p->next) {
		p = p->next;
	}
	p->next = newNode;
}

static void GenGraph(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize)
{
	int i;
	int from, to;
	struct Enode *p;

	gGraph.vNum = numCourses;
	gGraph.eNum = prerequisitesSize;

	for (i = 0; i < numCourses; i++) {
		gGraph.nodes[i].vectex = i;
	}

	for (i = 0; i < prerequisitesSize; i++) {
		from = prerequisites[i][1];
		to = prerequisites[i][0];

		p = (struct Enode *)calloc(1, sizeof(struct Enode));
		p->vIndex = to;
		if (gGraph.nodes[from].firstEdge == NULL) {
			gGraph.nodes[from].firstEdge = p;
		} else {
			AddToEnd(gGraph.nodes[from].firstEdge, p);
		}
	}
}

static void GraphPrint()
{
	int i;
	struct Enode *p;

	for (i = 0; i < gGraph.vNum; i++) {
		printf("%d : ", gGraph.nodes[i].vectex);
		p = gGraph.nodes[i].firstEdge;
		while (p) {
			printf("%d ", p->vIndex);
			p = p->next;
		}
		printf("\n");
	}
}

void GraphFree()
{
	int i;
	struct Enode *p, *oldP;

	for (i = 0; i < gGraph.vNum; i++) {
		p = gGraph.nodes[i].firstEdge;
		while (p) {
			oldP = p;
			p = p->next;
			free(oldP);
		}
	}
}

static int *TopSort(int *ans, int n, int *retNum)
{
	int ansIndex = 0;
	int *inRecord = (int *)calloc(1, sizeof(int) * n);
	int *stack = (int *)calloc(1, sizeof(int) * n);
	int top = 0;
	struct Enode *p;
	int i;
	int from, to;

	/* 统计各个点的入度 */
	for (i = 0; i < gGraph.vNum; i++) {
		p = gGraph.nodes[i].firstEdge;
		while (p) {
			to = p->vIndex;
			inRecord[to]++;
			p = p->next;
		}
	}

	/* 将入度为零的点入栈 */
	for (i = 0; i < n; i++) {
		if (inRecord[i] == 0) {
			stack[top++] = i;
		}	
	}

	/* 当栈非空的时候循环 */
	while (top != 0) {
		/* 栈顶元素出栈 */
		from = stack[top - 1];
		ans[ansIndex++] = from;
		top--;
		p = gGraph.nodes[from].firstEdge;
		while (p) {
			to = p->vIndex;
			inRecord[to]--;
			if (inRecord[to] == 0) {
				stack[top++] = to;
			}
			p = p->next;
		}
	}

	if (ansIndex != n) {
		*retNum = 0;
	} else {
		*retNum = ansIndex;
	}
	return ans;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize)
{
	int i;
	int *ans = (int *)calloc(1, sizeof(int) * numCourses);

	memset(&gGraph, 0, sizeof(gGraph));

	GenGraph(numCourses, prerequisites, prerequisitesSize, prerequisitesColSize);

	//GraphPrint();
	ans = TopSort(ans, numCourses, returnSize);
	GraphFree();

	for (i = 0; i < *returnSize; i++) {
		//printf("%d ", ans[i]);
	}
	return ans;
}

```
