### 解题思路
写得有点儿长，不过各函数功能独立，思路主要是递归
![image.png](https://pic.leetcode-cn.com/930df98b768bdfb9280506d9dc7a9f699b2bedec3990940580d58d74a705420b-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_OK 0
#define MY_FAIL (-1)

#define MY_USED 1
#define MY_UNUSED 0

struct MyRlt {
	int rltCnt;
	int rltSize;
	int **rlt;
	int *columnSizes;
};
struct MyStatus {
	int curCnt;
	int *curRlt;
};
int nCal(int n)
{
	int rlt = 1;
	while (n > 0) {
		rlt *= n;
		n--;
	}
	return rlt;
}
int cNM(int n, int m)
{
	int i;
	int rlt = 1;
	for (i = n; i > n - m; i--) {
		rlt *= i;
	}
	rlt /= nCal(m);
	return rlt;
}
void rltTrace(int *curRlt, int curCnt, int rltCnt)
{
	int i;
	printf("curCnt = %d, rltCnt = %d:", curCnt, rltCnt);
	for (i = 0; i < curCnt; i++) {
		printf("%d ", curRlt[i]);
	}
	printf("\n");
	return;
}
int rltInit(int *nums, int numsSize, struct MyRlt *r)
{
	int i;
	r->rltSize = 1; /* 必定有个空子集 */
	for (i = 1; i <= numsSize; i++) {
		r->rltSize += cNM(numsSize, i);
	}
	r->rltCnt = 0;
	r->rlt = (int**)calloc(r->rltSize, sizeof(int*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	r->columnSizes = (int*)calloc(r->rltSize, sizeof(int));
	if (r->columnSizes == NULL) {
		free(r->rlt);
		return MY_FAIL;
	}
	//printf("rltSize = %d\n", r->rltSize);
	return MY_OK;
}
int rltAdd(struct MyRlt *r, int *curRlt, int curCnt)
{
	int *buf = NULL;
	if (curCnt != 0) {
		buf	= (int*)calloc(curCnt, sizeof(int));
		if (buf == NULL) {
			return MY_FAIL;
		}
		memcpy(buf, curRlt, curCnt * sizeof(int));
	}
	r->rlt[r->rltCnt] = buf;
	r->columnSizes[r->rltCnt] = curCnt;
	r->rltCnt++;
	//rltTrace(curRlt, curCnt, r->rltCnt);
	return MY_OK;
}
int statusInit(int *nums, int numsSize, struct MyStatus *s)
{
	s->curRlt = (int*)calloc(numsSize, sizeof(int));
	if (s->curRlt == NULL) {
		return MY_FAIL;
	}
	s->curCnt = 0;
	return MY_OK;
}
void statusFree(struct MyStatus *s)
{
	if (s->curRlt != NULL) {
		free(s->curRlt);
		s->curRlt = NULL;
	}
	return;
}
int process(int* nums, int numsSize, struct MyRlt *r, struct MyStatus *s, int level)
{
	int i;
	if (level == 0) {
		rltAdd(r, s->curRlt, s->curCnt);
		return MY_OK;
	}
	for (i = 0; i < numsSize; i++) {
		s->curRlt[s->curCnt++] = nums[i];
		process(&nums[i + 1], numsSize - 1 - i, r, s, level - 1);
		s->curCnt--;
	}
	return MY_OK;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int i;
	struct MyRlt r;
	struct MyStatus s;
	rltInit(nums, numsSize, &r);
	statusInit(nums, numsSize, &s);
	rltAdd(&r, NULL, 0);
	for (i = 1; i <= numsSize; i++) {
		process(nums, numsSize, &r, &s, i);
	}
	statusFree(&s);
	*returnSize = r.rltCnt;
	*returnColumnSizes = r.columnSizes;
	return r.rlt;
}
```