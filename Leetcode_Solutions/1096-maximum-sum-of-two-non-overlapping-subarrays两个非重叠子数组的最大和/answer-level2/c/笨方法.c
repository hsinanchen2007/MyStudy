### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
int maxSumTwoNoOverlapSingleStep(int* sum, int left, int right, int len) {
	int ret, tmp, i, j;
	for (ret = 0, i = left, j = left + len - 1; j <= right; i++, j++) {
		tmp = sum[j + 1] - sum[i];
		ret = MAX(ret, tmp);
	}
	return ret;
}
int maxSumTwoNoOverlap(int* A, int ASize, int L, int M) {
    int *sum, i, j, tmp, left, right, ret;

	sum = (int *)calloc(ASize + 1, sizeof(int));
	sum[0] = 0;
	for (i = 1; i <= ASize; i++) {
		sum[i] = sum[i - 1] + A[i - 1];
	}
	ret = 0;
	for (i = 0, j = L - 1; j < ASize; i++, j++) {
		tmp = sum[j + 1] - sum[i];
		left = 0;
		if (i >= M) {
			left = maxSumTwoNoOverlapSingleStep(sum, 0, i - 1, M);
		}
		right = 0;
		if (ASize - i > M) {
			right = maxSumTwoNoOverlapSingleStep(sum, j + 1, ASize - 1, M);
		}
		tmp += MAX(left, right);
		ret = MAX(ret, tmp);
	}
    free(sum);
	return ret;
}
```