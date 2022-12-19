### 解题思路
算法是从下向上，
但是内存管理实在是复杂，C语言的强项也是弱项...
![image.png](https://pic.leetcode-cn.com/7f26186650ab75c3a86322be3e5f47b1fccb7aeb2368910a1e34cf065a596eb4-image.png)

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MY_OK 0
#define MY_FAIL (-1)
struct MyRlt {
	struct TreeNode** rlt;
	int rltSize;
	int rltCnt;
};

int copyTree(struct TreeNode **dst, struct TreeNode *src)
{
	if (src == NULL) {
		*dst = NULL;
		return MY_OK;
	}
	*dst = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	if (*dst == NULL) {
		return MY_FAIL;
	}
	(*dst)->val = src->val;
	return copyTree(&((*dst)->left), src->left) + copyTree(&((*dst)->right), src->right);
}
void freeTree(struct TreeNode *n)
{
	if (n == NULL) {
		return;
	}
	freeTree(n->left);
	freeTree(n->right);
	free(n);
	return;
}
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
	return;
}

int rltInit(struct MyRlt *r, int size)
{
	r->rltSize = size;
	r->rltCnt = 0;
	r->rlt = (struct TreeNode**)calloc(r->rltSize, sizeof(struct TreeNode*));
	if (r->rlt == NULL) {
		return MY_FAIL;
	}
	return MY_OK;
}

int rltAdd(struct MyRlt *r, struct TreeNode *cur)
{
	int ret;
	if (r->rltCnt == r->rltSize) {
		printf("buffer is not enough\n");
		return MY_FAIL;
	}
	ret = copyTree(&(r->rlt[r->rltCnt]), cur);
	r->rltCnt++;
	//printf("rltAdd: r->rltCnt = %d, r->rltSize = %d\n", r->rltCnt, r->rltSize);
	return ret;
}

int rltArrInit(struct MyRlt **rltArr, int N)
{
	struct MyRlt *lrltArr = NULL;
	lrltArr = (struct MyRlt*)calloc(N, sizeof(struct MyRlt));
	if (lrltArr == NULL) {
		return MY_FAIL;
	}
	*rltArr = lrltArr;
	return MY_OK;
}
int calSize(struct MyRlt *rltArr, int n)
{
	int i, j;
	int rlt = 0;
	if (n == 1) {
		return 1;
	}
	for (i = 1; i < n; i += 2) {
		for (j = n - 1 - i; j >= 1; j-= 2) {
			rlt += rltArr[i].rltCnt * rltArr[j].rltCnt;
		}
	}
	return rlt;
}
int process(struct MyRlt *rltArr, int n)
{
	int ret;
	int i, j, x, y;
	int size;
	struct TreeNode *cur = NULL;

	ret = rltInit(&rltArr[n], calSize(rltArr, n));
	if (ret != MY_OK) {
		return MY_FAIL;
	}
	cur = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
	if (cur == NULL) {
		return MY_FAIL;
	}
	if (n == 1) {
		ret = rltAdd(&rltArr[n], cur);
		if (ret != MY_OK) {
			free(cur);
			return MY_FAIL;
		}
		free(cur);
		return MY_OK;
	}
	for (i = 1; i < n; i += 2) {
		//printf("i = %d, n - 1 - i = %d, rltArr[i].rltCnt = %d, rltArr[j].rltCnt= %d\n", i, n - 1 - i, rltArr[i].rltCnt, rltArr[n - 1 - i].rltCnt);
		for (x = 0; x < rltArr[i].rltCnt; x++) {
			for (y = 0; y < rltArr[n - 1 - i].rltCnt; y++) {
				cur->left = rltArr[i].rlt[x];
				cur->right = rltArr[n - 1 - i].rlt[y];
				ret = rltAdd(&rltArr[n], cur);
				if (ret != MY_OK) {
					free(cur);
					return MY_FAIL;
				}
			}
		}
	}
	free(cur);
	return MY_OK;
}
struct TreeNode** allPossibleFBT(int N, int* returnSize){
	int i;
	int ret;
	struct MyRlt *rltArr = NULL;
	if (N % 2 == 0) {
		*returnSize = 0;
		return NULL;
	}
	ret = rltArrInit(&rltArr, N + 1);
	if (ret != MY_OK) {
		return NULL;
	}
	for (i = 1; i <= N; i += 2) {
		ret = process(rltArr, i);
		if (ret != MY_OK) {
			break;
		}
	}
	if (i != (N + 2)) {
		return NULL;
	}
	for (i = 0; i < N; i++) {
		rltFree(&rltArr[i]);
	}
	*returnSize = rltArr[N].rltCnt;
	return rltArr[N].rlt;
}
```