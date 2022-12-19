### 解题思路
使用动态规划来解决，转移方程为：dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j], 需要对就j>i-1和j-1<0做特殊处理

### 代码

```c
int min(int a, int b) {
	return a<b ? a : b;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
	int i, j;
	int col = triangleSize;
	int row = *triangleColSize;

	int **dp = (int **)malloc(col*sizeof(int*));
	for (i = 0; i < col; i++){
		dp[i] = (int*)malloc(sizeof(int)*col);
	}

	dp[0][0] = triangle[0][0];
	int minsum = 0x7fffffff;
    if(1 == col){
        return dp[0][0];
    }
	for (i = 1; i < col; i++){
		for (j = 0; j <= i; j++){
			int tmp, flag;
            //上一行最大下表元素为dp[i-1][i-1]
            //j > i-1时即下标大于上一行的对角线
			if (j > i-1){
				tmp = 0x7fffffff;
			}
			else {
                //j不大于i-1
				tmp = dp[i - 1][j];
			}
            //j等于0时j - 1 < 0，即对第一列进行处理
			if (j - 1 < 0){
				flag = 0x7fffffff;
			}
			else {
				flag = dp[i - 1][j - 1];
			}
			dp[i][j] = min(tmp, flag) + triangle[i][j];
			if (col-1 ==i  && minsum > dp[i][j]){
				minsum = dp[i][j];
			}
		}
	}
	return minsum;
}
```