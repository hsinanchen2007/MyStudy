### 解题思路
转移方程：dp[i]=max(dp[-1],dp[i-2]+nums[i])

解释：当前天的数值取决于前一次的最大值和上上一次的最大值加上本次的预约
### 代码

```golang
func massage(nums []int) int {
	if len(nums)==0{
		return 0
	}
	if len(nums)==1{
		return nums[0]
	}
	dp:=0
	pre:=0
	prepre:=0
	for i:=0;i<len(nums);i++{
		dp=max(pre,prepre+nums[i])
		prepre=pre//前天
		pre=dp //昨天
	}
	return dp
}


func max(a,b int) int {
	if a>b{
		return a
	}
	return b
}
```