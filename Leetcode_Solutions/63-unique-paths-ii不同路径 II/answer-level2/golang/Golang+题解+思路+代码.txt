### 题解:

- 题目跟之前那个 `不同路径` 是差不多的!不过有区别是这个有障碍
- 障碍的标记点为`1`,所以可以根据`值` 确定该点是不是障碍点
- 障碍点右边和下边的点 可能只有一个方向来!  

### 思路:

- 还是动归,还是记录每个点的路径的可能性
- 一旦遇到障碍点,障碍点的路径可能性 设置为 0,这样其他获得左边+上面的和时候,就不需要考虑左/上边是不是障碍点了!
- 但是要注意: 如果是 x轴或者y轴有个障碍点,比如x轴有个障碍点,那么这个障碍点右边的路径都是0, 比如 [0,1,0,0,0],`1`右边所有的路径可能性都是0
- 如果y轴有一个障碍点,同理,该障碍点下面的所有点的路径可能性都是`0`

### 代码:

 ```go
 n := len(obstacleGrid)
 	m := len(obstacleGrid[0])
 
 	dp := make([][]int,n)
 
 	for i:=0;i<n;i++ {
 		dps := make([]int,m)
 		for j:=0;j<m;j++ {
 			if obstacleGrid[i][j] == 1 {
 				dps[j] = 0
 				dp[i] = dps
 				continue
 			}
 
 			if j == 0 && i == 0 {
 				dps[0] = 1
 				dp[i] = dps
 				continue
 			}
 
 			if i == 0 {
 				dps[j] = dp[i][j-1]
 				dp[i] = dps
 				continue
 			}
 
 			if j == 0 {
 				dps[j] = dp[i-1][j]
 				dp[i] = dps
 				continue
 			}
 
 			dps[j] = dp[i-1][j] + dp[i][j-1]
 			dp[i] = dps
 		}
 	}
 	return dp[n-1][m-1]
 ```

### 该题已整理在网站里，有在面试的，可自取，地址： [interview](http://interview.wzcu.com/)