C 语言版本的实现，使用 tarjan 算法来寻找强连通节点，没有进一步优化，另外题目的参数设计有点问题：
- connectionsColSize: 没有意义, 各个值都是 2
- returnColumnSizes: 同上

```c
typedef struct Stack {
	int current;
	int length;
	int *data;
} Stack;

void pushStack(Stack *stack, int v) {
	if (stack->current >= stack->length) {
		if (stack->data == NULL) {
			stack->length = 4;
		} else {
			stack->length *= 2;
		}

		// here I assume the memory is enough, and why not ?
		stack->data = (int *) realloc(stack->data, sizeof(int) * stack->length);
	}

	stack->data[stack->current++] = v;
}

int popStack(Stack *stack) {
	if (stack->current == 0) {
		return -1;
	}

	stack->current--;
	return stack->data[stack->current];
}

void releaseStack(Stack *stack) {
	if (stack->data != NULL) {
		free(stack->data);
	}
}

// ConnectNode used to record the connections starts from each node
typedef struct Stack ConnectNode;

void setNext(ConnectNode *list, int v, int next) {
	pushStack(list + v, next);
}

void releaseConnectNode(ConnectNode *node) {
	releaseStack(node);
}

typedef struct TarJanData {
	// the current time for deep-first searching
	int time;
	// 'flags' used to mark which node is visited
	unsigned int* flags;
	/*
	 * after find the strongly connected nodes,
	 * set them to same value in 'replace' list
	 */
	int* replace;
	Stack *s;
	int* dfn;
	int* low;
} TarJanData;

void releaseTarJanData(TarJanData t) {
	free(t.flags);
	free(t.replace);
	free(t.dfn);
	free(t.low);
	releaseStack(t.s);
}

#define MIN(x, y) ((x) > (y) ? (y) : (x))
#define FLAG_SET(flags, index) (flags[index/32] |= ((unsigned int)1 << (index%32)))
#define FLAG_EXT(flags, index) (flags[index/32] &  ((unsigned int)1 << (index%32)))

void tarjan(ConnectNode *connectList, TarJanData *t, int parent, int v) {
	ConnectNode *n = connectList + v;

	pushStack(t->s, v);
	FLAG_SET(t->flags, v);
	t->dfn[v] = t->low[v] = ++(t->time);

	int i;
	int next;
	for (i = 0; i < n->current; i++) {
		// ignore the same connection
		if (parent == n->data[i]) {
			continue;
		}

		next = n->data[i];
		if (FLAG_EXT(t->flags, next)) {
			t->low[v] = MIN(t->low[v], t->dfn[next]);
		} else {
			tarjan(connectList, t, v, next);
			t->low[v] = MIN(t->low[v], t->low[next]);
		}
	}

	if (t->dfn[v] == t->low[v]) {
		int top;
		for (top = popStack(t->s); top != -1 && top != v; top = popStack(t->s)) {
			t->replace[top] = v;
		}
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize,
		int* returnSize, int** returnColumnSizes) {
	ConnectNode *connectList = (ConnectNode *) malloc (sizeof(ConnectNode) * n);
	memset(connectList, 0, sizeof(ConnectNode) * n);

	// set the next nodes of each node
	int i;
	for (i = 0; i < connectionsSize; i++) {
		setNext(connectList, connections[i][0], connections[i][1]);
		setNext(connectList, connections[i][1], connections[i][0]);
	}

	// prepare the TarJanData
	int flagBytes = sizeof(unsigned int) * (n / sizeof(unsigned int) + 1);
	unsigned int* flags = (unsigned int*) malloc (flagBytes);
	memset(flags, 0, flagBytes);

	int* replace = (int*) malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		replace[i] = i;
	}

	Stack s = {0, 0, NULL};

	TarJanData t = {
		0, flags, replace, &s,
		(int*) malloc(sizeof(int) * n), // 'dfn' and 'low' do not need memset to 0
		(int*) malloc(sizeof(int) * n),
	};

	// do dfs search
	tarjan(connectList, &t, connections[0][0], connections[0][0]);

	// here we got a 'replace' list, if the nodes' value are same, they are strongly connected,
	// if they have different values, the connection between them are 'criticalConnections'.
	int criticalNum = 0;
	for (i = 0; i < connectionsSize; i++) {
		if (t.replace[connections[i][0]] != t.replace[connections[i][1]]) {
			criticalNum++;
		}
	}

	if (criticalNum == 0) {
		*returnSize = 0;
		*returnColumnSizes = NULL;
		return NULL;
	}

	int j = 0;
	int** criticalResult = (int **) malloc (criticalNum * sizeof(int *));
	int *criticalColumnSizes = (int *) malloc(criticalNum * sizeof(int));
	for (i = 0; i < connectionsSize; i++) {
		if (t.replace[connections[i][0]] != t.replace[connections[i][1]]) {
			criticalResult[j] = (int *) malloc (sizeof(int) * 2);
			criticalResult[j][0] = connections[i][0];
			criticalResult[j][1] = connections[i][1];
			criticalColumnSizes[j] = 2;
			j++;
		}
	}

	// free
	for (i = 0; i < n; i++) {
		releaseConnectNode(connectList + i);
	}
	free(connectList);
	releaseTarJanData(t);

	*returnSize = criticalNum;
	*returnColumnSizes = criticalColumnSizes;
	return criticalResult;
}
```
