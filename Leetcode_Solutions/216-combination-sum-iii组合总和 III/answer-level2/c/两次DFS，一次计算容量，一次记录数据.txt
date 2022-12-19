### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define min(x, y) ((x) > (y) ? (y) : (x))

#define max(x, y) ((x) > (y) ? (x) : (y))

int g_cnt = 0;
int DFSCnt(int k, int n, int lastNum, int lastCnt, int total, int *flag)
{

	if (lastCnt == k) {
		if (total == n) {
			g_cnt++;
		}
		return 0;
	}

	int i;
	for (i = lastNum + 1; i <= 9; i++) {
		if (flag[i] == 0 && total + i <= n) {
			flag[i] = 1;
			DFSCnt(k, n, i, lastCnt + 1, total + i, flag);
			flag[i] = 0;
		}
	}
	return 0;
}

int DFSRet(int k, int n, int lastNum, int lastCnt, int total, int *flag, int *record, int **ret)
{

	if (lastCnt == k) {
		if (total == n) {
			memcpy(ret[g_cnt], record, k * sizeof(int));
			g_cnt++;
		}
		return 0;
	}

	int i;
	for (i = lastNum + 1; i <= 9; i++) {
		if (flag[i] == 0 && total + i <= n) {
			flag[i] = 1;
			record[lastCnt] = i;
			DFSRet(k, n, i, lastCnt + 1, total + i, flag, record, ret);
			flag[i] = 0;
		}
	}
	return 0;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
	g_cnt = 0;
	printf("k %d n %d \n", k, n);


	int *flag = (int *)malloc(10 * sizeof(int));
	memset(flag, 0, 10 * sizeof(int));

	DFSCnt(k, n, 0, 0, 0, flag);
	memset(flag, 0, 10 * sizeof(int));

	printf("g_cnt %d \n", g_cnt);
	*returnSize = g_cnt;
	int *col = (int*)malloc(g_cnt * sizeof(int));
	int i;
	for (i = 0; i < g_cnt; i++) {
		col[i] = k;
	}
	*returnColumnSizes = col;


	int *record = (int *)malloc(k * sizeof(int));
	memset(record, 0, k * sizeof(int));

	int **ret = (int **)malloc(g_cnt * sizeof(int **));
	for (i = 0; i < g_cnt; i++) {
		ret[i] = (int *)malloc(k * sizeof(int));
		memset(ret[i], 0, k * sizeof(int));
	}

	g_cnt = 0;
	DFSRet(k, n, 0, 0, 0, flag, record, ret);


	return ret;
}
```