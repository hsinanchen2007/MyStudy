### 解题思路


### 代码
![企业微信截图_15821855478763.png](https://pic.leetcode-cn.com/e0d47af7cd564e04bca8d764f7e40da80b9088ca7b6deeffa0c58c0cfab630b4-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_15821855478763.png)


```c
int min(int a, int b) {
	return a<b ? a : b;
}

int minPathSum(int** grid, int gridSize, int* gridColSize){
	int i, j;
    //需要注意这个题的行和列是反的, *gridColSize实际是列的长度
	int col = gridSize;
	int row = *gridColSize;

    //根据行和列动态申请放置结果的二维数组
	int **dp = (int **)malloc(col*sizeof(int*));
	for (i = 0; i < col; i++){
		dp[i] = (int*)malloc(sizeof(int)*row);
	}
    
    //初始化dp数组，只有一个元素时将grid[0][0]直接赋值给dp[0][0]
	dp[0][0] = grid[0][0];
    //对第一列赋初值，输入数组只有一列时只有一种走法，每走一步时最小值就是上一步的值加上grid数组中当前值
	for (i = 1; i < col; i++){
		dp[i][0] = dp[i-1][0] + grid[i][0];
	}
    //对第一行赋初值，输入数组只有一行时只有一种走法，每走一步时最小值就是上一步的值加上grid数组中当前值
	for (i = 1; i < row; i++){
		dp[0][i] = dp[0][i-1] + grid[0][i];
	}
    //使用递推公式进行求解
	for (i = 1; i < col; i++){
		for (j = 1; j < row; j++){
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
		}
	}

	return dp[col-1][row-1];
}
```