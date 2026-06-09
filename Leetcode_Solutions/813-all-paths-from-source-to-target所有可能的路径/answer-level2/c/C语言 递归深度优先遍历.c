### 解题思路
递归深度优先遍历
rlt的size是固定8192，这个待优化成动态扩容的
![image.png](https://pic.leetcode-cn.com/3ee6771fe2cea39756ecd1f1305bbd2eeb75265483be745c895a0fadbb75e329-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_RLT_BASE_SIZE 8192
#define MY_STOP_MAX 15
#define MY_INVALID_STOP (-1)

struct MyRlt {
	int rltSize;
	int rltCnt;
	int **rlt;
	int *rltColumnSizes;
};
struct MyStatus {
	int curCnt;
	int *curBuf;
	char **map;
};
void rltFree(struct MyRlt *r)
{
	int i;
	if (r == NULL) {
		return;
	}
	if (r->rlt != NULL) {
		for (i = 0; i < r->rltCnt; i++) {
			if (r->rlt[i] != NULL) {
				free(r->rlt[i]);
				r->rlt[i] = NULL;
			}
		}
		free(r->rlt);
		r->rlt = NULL;
	}
	if (r->rltColumnSizes != NULL) {
		free(r->rltColumnSizes);
		r->rltColumnSizes = NULL;
	}
	return;
}
int rltInit(struct MyRlt *r)
{
	if (r == NULL) {
		return MY_FAIL;
	}
	r->rltSize = MY_RLT_BASE_SIZE;
	r->rltCnt = 0;
	r->rlt = (int**)calloc(r->rltSize, sizeof(int*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	r->rltColumnSizes = (int*)calloc(r->rltSize, sizeof(int));
	if (r->rltColumnSizes == NULL) {
		free(r->rlt);
		r->rlt = NULL;
		return MY_FAIL;
	}
	return MY_OK;
}
int rltAdd(struct MyRlt *r, struct MyStatus *s)
{
	int *buf = NULL;
	if (r->rltCnt == r->rltSize) {
		printf("buffer is not enough\n");
		return MY_FAIL;
	}
	buf = (int*)calloc(s->curCnt, sizeof(int));
	if (buf == NULL) {
		return MY_FAIL;
	}
	memcpy(buf, s->curBuf, s->curCnt * sizeof(int));
	r->rlt[r->rltCnt] = buf;
	r->rltColumnSizes[r->rltCnt] = s->curCnt;
	r->rltCnt++;
	return MY_OK;
}
void staFree(struct MyStatus *s)
{
	int i;
	if (s == NULL) {
		return;
	}
	if (s->curBuf != NULL) {
		free(s->curBuf);
		s->curBuf = NULL;
	}
	if (s->map != NULL) {
		for (i = 0; i < MY_STOP_MAX; i++) {
			if (s->map[i] != NULL) {
				free(s->map[i]);
				s->map[i] = NULL;
			}
		}
		free(s->map);
		s->map = NULL;
	}
	return;
}
int staInit(struct MyStatus *s)
{
	int i;
	if (s == NULL) {
		return MY_FAIL;
	}
	s->map = (char**)calloc(MY_STOP_MAX, sizeof(char*));
	if (s->map == NULL) {
		return MY_FAIL;
	}
	for (i = 0; i < MY_STOP_MAX; i++) {
		s->map[i] = (char*)calloc(MY_STOP_MAX, sizeof(char));
		if (s->map[i] == NULL) {
			staFree(s);
			return MY_FAIL;
		}
		memset(s->map[i], MY_INVALID_STOP, MY_STOP_MAX * sizeof(char));
	}
	s->curCnt = 0;
	s->curBuf = (int*)calloc(MY_STOP_MAX, sizeof(int));
	if (s->curBuf == NULL) {
		staFree(s);
		return MY_FAIL;
	}
	
	return MY_OK;
}
void prepareMap(int** graph, int graphSize, int* graphColSize, struct MyStatus *s)
{
	int i, j;
	for (i = 0; i < graphSize; i++) {
		for (j = 0; j < graphColSize[i]; j++) {
			s->map[i][graph[i][j]] = graph[i][j];
		}
	}
	return;
}
void processMap(struct MyStatus *s, struct MyRlt *r, int startNode, int endNode)
{
	int i;
	//printf("startNode = %d, endNode = %d\n", startNode, endNode);
	s->curBuf[s->curCnt] = startNode;
	s->curCnt++;
	for (i = 0; i < MY_STOP_MAX; i++) {
		if (s->map[startNode][i] == MY_INVALID_STOP) {
			continue;
		}
		if (s->map[startNode][i] == endNode) {
			s->curBuf[s->curCnt] = endNode;
			s->curCnt++;
			rltAdd(r, s);
			s->curCnt--;
			continue;
		}
		processMap(s, r, s->map[startNode][i], endNode);
	}
	s->curCnt--;
	return;
}
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
	int ret;
	struct MyRlt r = { 0 };
	struct MyStatus s = { 0 };
	ret = rltInit(&r);
	ret |= staInit(&s);
	if (ret != MY_OK) {
		rltFree(&r);
		staFree(&s);
		return NULL;
	}
	prepareMap(graph, graphSize, graphColSize, &s);
	processMap(&s, &r, 0, graphSize - 1);
	staFree(&s);
	*returnSize = r.rltCnt;
	*returnColumnSizes = r.rltColumnSizes;
	return r.rlt;
}
```