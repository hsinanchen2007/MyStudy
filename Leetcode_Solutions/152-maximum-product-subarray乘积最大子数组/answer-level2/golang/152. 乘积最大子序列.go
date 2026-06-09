

//做DP，通用
```
func maxProduct(nums []int) int {
    if len(nums) <= 0 {
        return 0
    }
    var dp  = [2][2]int{{0, 0,},{0, 0}}
    dp[0][1],dp[0][0] = nums[0],nums[0]
    res := nums[0]
    for i:= 1;i<len(nums);i++{
        //就是0，1 交替利用空间
        x,y := i%2,(i-1)%2
        //max 
        dp[x][0] = max(max(dp[y][0]*nums[i],dp[y][1]*nums[i]), nums[i])
        //minus-max
        dp[x][1] = min(min(dp[y][0]*nums[i],dp[y][1]*nums[i]),nums[i])
        res = max(res,dp[x][0])
    }
    return res
}

func max(a int, b int) int {
	if a > b{
		return a
	}
	return b
}

func min(a int, b int) int {
	if a > b{
		return b
	}
	return a
}
```

//易懂针对这题
```
func maxProduct(nums []int) int {
    if len(nums) == 0 {
		return 0
	}
    res,curMax,curMin := nums[0],nums[0],nums[0]
    for i:=1;i< len(nums);i++{
        n := nums[i]
        curMax,curMin = curMax*n ,curMin*n
        curMax,curMin = max(max(curMax,curMin),n),min(min(curMax,curMin),n)
        if curMax > res{
            res = curMax
        }
    }
	
	return res
}

```