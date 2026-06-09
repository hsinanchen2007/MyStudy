注意如果使用了全局变量，一定要初始化，因为leetCode会在一次执行中多次测试……
```

#define MAX_N 45
#define MAX_K 9
#define MAX_CNT 45

#define min(a, b) ((a) < (b)) ? (a) : (b)

int row = 0;
int out[MAX_CNT][MAX_K] = {{0}};
int CalcOut(int *temp, int totalK, int k, int n, int start, int end) {
	int i;
	int ret = 1;
	int tmpk, tmpn;
	int tmpEnd, tmpStart;
	int *tmp;

	tmp = (int *)malloc(totalK * sizeof(int));
	memcpy(tmp, temp, totalK * sizeof(int));
	if (k == 1 && n <= 9) {
		tmp[totalK - 1] = n;
		memcpy(out[row], tmp, totalK * sizeof(int));
		row++;
		return 1;
	} else if (k == 1 && n > 9) {
		return 0;
	}
	for (i = start; i <= min(end, MAX_K); i++) {
		tmp[totalK - k] = i;
		tmpk = k - 1;
		tmpn = n - i;
		tmpStart = i + 1;
		tmpEnd = tmpn / tmpk;
		if (tmpStart > tmpEnd) {
			break;
		}
		ret = CalcOut(tmp, totalK, tmpk, tmpn, tmpStart, tmpEnd);
	}
    free(tmp);
	return ret;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
	int i;
	int cnt = 0;
	int ret = 0;
	int **output;
	int *temp;

	if (n > MAX_N || k > MAX_K || k > n || n > 9 * k) {
        *returnSize = 0;
        returnColumnSizes = (int **)NULL;
		return (int **)NULL;
	}
	temp = (int *)malloc(k * sizeof(int));
	memset(temp, 0 , k * sizeof(int));
    memset(out, 0, sizeof(out));
    row = 0;
	ret = CalcOut(temp, k, k, n, 1, n / k);
	if (ret == 0) {
		row--;
	}
	if (row < 0) {
        *returnSize = 0;
        returnColumnSizes = (int **)NULL;
		return (int **)NULL;
	}
	cnt = row;
	output = (int **)malloc(cnt * sizeof(int *));
    *returnSize = cnt;
	returnColumnSizes[0] = (int *)malloc(cnt * sizeof(int));
	for (i = 0; i < cnt; i++) {
		output[i] = (int *)malloc(k * sizeof(int));
		memcpy(output[i], out[i], k * sizeof(int));
		returnColumnSizes[0][i] = k;
	}
    free(temp);
	return output;
}
```
