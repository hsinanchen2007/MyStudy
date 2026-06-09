#include <stdio.h>

#define MAX_NUM 1024
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int dp[MAX_NUM] = { 0 };

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize)
{
	int i, j;
	int *row;

	/* 初始化边界条件 */
	row = triangle[triangleSize - 1];
	memcpy(dp, row, sizeof(int) * triangleSize);

	if (triangleSize == 1) {
		return dp[0];
	}

	for (i = triangleSize - 2; i >= 0; i--) {
		row = triangle[i];
		for (j = 0; j <= i; j++) {
			dp[j] = *(row + j) + MIN(dp[j], dp[j + 1]);
		}
	}

	return dp[0];
}