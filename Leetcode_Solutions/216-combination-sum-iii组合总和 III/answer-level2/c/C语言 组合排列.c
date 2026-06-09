### 解题思路
题目就是求组合，使用了递归
![image.png](https://pic.leetcode-cn.com/7b7093dbf5aa379811b3075c1596f206bf1038f8f0502f52a2e4570959dca1d3-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_BASE_SIZE 1024
#define MY_CNT 9

#define MY_OK 0
#define MY_FAIL (-1)
struct MyRlt {
	int **rlt;
	int *returnColumnSizes;
	int cnt;
	int size;
};

struct MyStatus{
	int *cur;
	int cnt;
};
void rltFree(struct MyRlt *r)
{
	if (r->rlt != NULL) {
		free(r->rlt);
		r->rlt = NULL;
	}
	if (r->returnColumnSizes != NULL) {
		free(r->returnColumnSizes);
		r->returnColumnSizes = NULL;
	}
	return;
}
int rltInit(struct MyRlt *r)
{
	r->size = MY_BASE_SIZE;
	r->cnt = 0;
	r->rlt = (int**)calloc(r->size, sizeof(int*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	r->returnColumnSizes = (int*)calloc(r->size, sizeof(int));
	if (r->returnColumnSizes == NULL) {
		free(r->rlt);
		return MY_FAIL;
	}
	return MY_OK;
}

int rltAdd(struct MyRlt *r, struct MyStatus *s)
{
	int *cur = NULL;
	if (r->cnt == r->size) {
		printf("buffer is not enough\n");
		return MY_FAIL;
	}
	cur = (int*)calloc(s->cnt, sizeof(int));
	if (cur == NULL) {
		return MY_FAIL;
	}
	memcpy(cur, s->cur, s->cnt * sizeof(int));
	r->rlt[r->cnt] = cur;
	r->returnColumnSizes[r->cnt] = s->cnt;
	r->cnt++;
	return MY_OK;
}
void statusFree(struct MyStatus *s)
{
	if (s->cur != NULL) {
		free(s->cur);
		s->cur = NULL;
	}
	return;
}
int statusInit(struct MyStatus *s)
{
	s->cur = (int*)calloc(MY_CNT, sizeof(int));
	if (s->cur == NULL) {
		return MY_FAIL;
	}
	s->cnt = 0;
	return MY_OK;
}
void traceStatus(struct MyStatus *s)
{
	int i;
	printf("s->cnt = %d, ", s->cnt);
	for (i = 0; i < s->cnt; i++) {
		printf("%d ", s->cur[i]);
	}
	printf("\n");
}
int process(struct MyRlt *r, struct MyStatus *s, int level, int k, int n)
{
	int i, ret;
	if (n < 0) {
		return MY_OK;
	}
	if (k == 0 && n == 0) {
		//traceStatus(s);
		return rltAdd(r, s);
	}
	for (i = level; i <= MY_CNT; i++) {
		s->cur[s->cnt++] = i;
		ret = process(r, s, i + 1, k - 1, n - i);
		if (ret != MY_OK) {
			return ret;
		}
		s->cnt--;
	}
	return MY_OK;
}
int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
	int ret;
	struct MyRlt r;
	struct MyStatus s;
	ret = rltInit(&r);
	ret |= statusInit(&s);
	if (ret != MY_OK) {
		rltFree(&r);
		statusFree(&s);
		return NULL;
	}
	
	ret = process(&r, &s, 1, k, n);
	if (ret != MY_OK) {
		rltFree(&r);
		statusFree(&s);
		return NULL;
	}
	statusFree(&s);
	*returnSize = r.cnt;
	*returnColumnSizes = r.returnColumnSizes;
	return r.rlt;
}
```