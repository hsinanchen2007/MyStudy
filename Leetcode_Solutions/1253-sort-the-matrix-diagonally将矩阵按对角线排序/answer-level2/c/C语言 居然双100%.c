### 解题思路
就是按照题目来，思路没什么，不过对内存错误进行了判断和处理
![image.png](https://pic.leetcode-cn.com/1ca366434de299206f397bdd1b397488bdf9d6302b911713ab61fa27c69d8ce8-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL -1
struct MyRlt {
	int **rlt;
	int rltSize;
	int *rltColumnSizes;
};
struct MyStatus {
	int startX;
	int startY;
	int bufSize;
	int *buf;
};
void rltFree(struct MyRlt *r)
{
	int i;
	if (r == NULL) {
		return;
	}
	if (r->rlt != NULL) {
		for (i = 0; i < r->rltSize; i++) {
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
int rltAlloc(struct MyRlt *r, int matSize, int matColSize)
{
	int i;
	if (r == NULL) {
		return MY_FAIL;
	}
	r->rltSize = matSize;
	r->rlt = (int**)calloc(r->rltSize, sizeof(int*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	for (i = 0; i < r->rltSize; i++) {
		r->rlt[i] = (int*)calloc(matColSize, sizeof(int));
		if (r->rlt[i] == NULL) {
			rltFree(r);
			return MY_FAIL;
		}
	}
	r->rltColumnSizes = (int*)calloc(r->rltSize, sizeof(int));
	if (r->rltColumnSizes == NULL) {
		rltFree(r);
		return MY_FAIL;
	}
	for (i = 0; i < r->rltSize; i++) {
		r->rltColumnSizes[i] = matColSize;
	}
	return MY_OK;
}

int staAlloc(struct MyStatus *s, int bufSize)
{
	if (s == NULL) {
		return MY_FAIL;
	}
	s->bufSize = bufSize;
	s->buf = (int*)calloc(s->bufSize, sizeof(int));
	if (s->buf == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}
void staFree(struct MyStatus *s)
{
	if (s == NULL) {
		return;
	}
	if (s->buf != NULL) {
		free(s->buf);
		s->buf = NULL;
	}
	return;
}
int cmp(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}
void process(int** mat, int matSize, int matColSize, struct MyStatus *s, struct MyRlt *r)
{
	int i, j;
	int cnt;
	cnt = 0;
	for (i = s->startX, j = s->startY; i < matSize && j < matColSize; i++, j++) {
		s->buf[cnt++] = mat[i][j];
	}
	qsort(s->buf, cnt, sizeof(int), cmp);
	cnt = 0;
	for (i = s->startX, j = s->startY; i < matSize && j < matColSize; i++, j++) {
		r->rlt[i][j] = s->buf[cnt++];
	}
	return;
}
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
	int ret;
	int i;
	struct MyRlt r;
	struct MyStatus s;
	ret = rltAlloc(&r, matSize, matColSize[0]);
	ret |= staAlloc(&s, matSize < matColSize[0] ? matSize : matColSize[0]);
	if (ret != MY_OK) {
		rltFree(&r);
		staFree(&s);
		return NULL;
	}

	for (i = 0; i < matColSize[0]; i++) {
		s.startX = 0;
		s.startY = i;
		process(mat, matSize, matColSize[0], &s, &r);
	}
	for (i = 0; i < matSize; i++) {
		s.startX = i;
		s.startY = 0;
		process(mat, matSize, matColSize[0], &s, &r);
	}
	staFree(&s);
	*returnSize = r.rltSize;
	*returnColumnSizes = r.rltColumnSizes;
	return r.rlt;
}
```