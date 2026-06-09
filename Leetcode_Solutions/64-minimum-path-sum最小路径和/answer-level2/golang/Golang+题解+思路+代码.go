### 题解:

- 二位矩阵,在golang里可以说是一个二维切片或者数组
- 从左上角到右下角的值最小
- 除了最底下和最右边的,其他的数都可以往右或者往下走!
- 矩阵可能只有一行

### 思路:

- 暴力解法!暴力算法其实不太适合,因为一旦矩阵过大,那么时间复杂度相当的高
- 动态规划
  - 以上面的例子为例,起点为1
  - 如果右移一位,到达`3`的最小值应该是 3左边的最小值加上自己,就是 1+3,如果再右移到1的位置,那么这个`1`的路径最小值就是左边最小值+自己,就是 4+1
  - 假设此刻走到中间的`5`这个数,那么从起点到`5`最小值就是  起点到5左右的`1`的最小值或者5上面的`3`的最小值,他两谁小,那么就从谁那到`5`就是最小的
  - 一直到右下角的`1`,右下角的`1`与起点的最小值取决于`1`左边的2到起点的最小值和`1`上边的1到起点的最小值,
  - 注意最左侧一列和最顶上一列数据的特殊情况,他们只有一个方向...
  
### 代码:


 ```go
func minPathSum(grid [][]int) int {
    // 取纵向
	m := len(grid)
	// 取横向
	n := len(grid[0])

	if m == 0 {
		return 0
	}
    
    // 定义一个二维切片来存起点到该点的最小值
	dp := make([][]int,m)

	for i:=0;i<m;i++ {
		dp[i] = make([]int,n)
		for j:=0;j<n;j++ {
			var left, top int
			if i == 0 && j == 0 {
				dp[0][0] = grid[0][0]
				continue
			}
			if i == 0 {
				dp[0][j] = dp[0][j-1]+grid[i][j]
				continue
			}  else {
				left = dp[i-1][j]
			}

			if j == 0 {
				dp[i][0] = dp[i-1][0]+grid[i][j]
				continue
			} else {
				top = dp[i][j-1]
			}
			dp[i][j] = min(left,top)+grid[i][j]
		}
	}
	return dp[m-1][n-1]
}

func min(a,b int) int {
	if a < b {
		return a
	}
	return b
}
 ```

### 正在面试的自取  [interview](http://interview.wzcu.com/)