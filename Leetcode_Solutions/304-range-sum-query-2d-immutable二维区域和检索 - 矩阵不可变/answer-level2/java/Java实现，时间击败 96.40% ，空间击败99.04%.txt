### 解题思路
因为是一个固定的矩阵，可以考虑先将所有结果初始化一次，假设从0,0开始，到每一个格子col,row的和可以拆解为4部分：
第一部分：0,0到row,col-1
第二部分：0,0到row-1,col
第三部分：由于前两部分重复计算了从0,0到row-1与col-1的和，所以需要把这个重复部分减掉
第四部分：加上此刻matrix[row][col]的值
所以考虑转态转移方程为：dp[row][col] = dp[row][col-1] + dp[row-1][col] - dp[row-1][col-1] + matrix[row][col]  (当然需要考虑边界情况，row==0或者col==0的情况);

初始化完成后，剩下的就比较简单了，从任意row,col到row1,col1的和可以拆解为0,0到row1,col1 减去多余的部分
1.0,0到row1-1,col
2.0,0到row,col-1
3.将减去的重复部分0,0到row-1,col-1加上即可
![image.png](https://pic.leetcode-cn.com/f81edd67b085e17d9ea8e19f97a9166285d0d2f5c761938302bce33286d119b8-image.png)
图中灰色 - 黄色 - 绿色 + 红色 即为所求的青色的和 



### 代码

```java
class NumMatrix {
    int[][] matrix;
	int[][] dp;
    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;
		if(matrix != null && matrix.length != 0) {
			dp = new int[matrix.length][matrix[0].length];
			initialDp(matrix, dp);
		}
    }
    private void initialDp(int[][] matrix, int[][] dp) {
		for(int i=0; i<matrix.length; i++) {
			for(int j=0; j<matrix[0].length; j++) {
				if(i == 0 && j == 0) {
					dp[i][j] = matrix[i][j];
				}else if(i == 0) {
					dp[i][j] = matrix[i][j] + dp[i][j-1];
				}else if(j == 0) {
					dp[i][j] = matrix[i][j] + dp[i-1][j];
				}else {
					dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
				}
			}
		}
	}

    public int sumRegion(int row1, int col1, int row2, int col2) {
        if(dp == null || dp.length == 0) {
			return 0;
		}
		//左边部分
		int left = 0;
		//上边部分
		int top = 0;
		//左上部分
		int leftTop = 0;
		if(col1 != 0) {
			left = dp[row2][col1-1];
		}
		if(row1 != 0) {
			top = dp[row1-1][col2];
		}
		
		if(col1 != 0 && row1 != 0) {
			leftTop = dp[row1-1][col1-1];
		}
		return dp[row2][col2] - left - top + leftTop;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
```