### 解题思路
从这个问题可以得出
1. 求最大值
2. 有两个状态， 预约和不预约 

说明动态规划可以解决。
然后就是状态转移方程
当前的状态和之前的状态有什么关系。 
和青蛙跳台阶是一样的。 
跳到这一级有多少个跳法，每次能跳一下， 或者能跳两下。 
那这个青蛙可能是从 n -1 or n-2 跳上来的。
即  dp[i] = dp(i-1) + dp[i-2] 
本次预约与否， 于前一次的预约与否有关系 
dp[i][1] 代表本次预约, 那么上次一定不能预约
dp[i][0] = dp[i-1][0] + nums[i](本次预约的值) 
dp[i][1] = max (dp[i-1][0], dp[i-1][1]) 


### 代码

```golang
func massage(nums []int) int {
	//两个状态， 预约， 或者不预约
	//目前的值取决于前一个是否预约
	//本次不预约
	//dp[i][0] =  dp[i-1][1] + nums[i]
	//dp[i][1] =  max(dp[i-1][0], dp[i-1][1] )

  if len(nums) < 1 {
    return 0
  }
	dp := make([][]int, len(nums))
	for i := range dp {
		dp[i] = make([]int, 2)
	}

	dp[0][0] = 0
	dp[0][1] = nums[0]

	for i := 1; i < len(nums); i++ {
    //当前预约等于  = 上个不预约 + 这个的值
		dp[i][1] = dp[i-1][0] + nums[i]
    //当前不预约  = max(上个预约 + 上个不预约)
		dp[i][0] = max(dp[i-1][0], dp[i-1][1])
	}

	return max(dp[len(nums)-1][0], dp[len(nums)-1][1])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```