### 解题思路
此处撰写解题思路

### 代码

```golang

func lengthOfLIS(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}

	n := len(nums)
	var dp = make([]int, n)
    for i := 0; i < n; i ++ {
        dp[i] =1
    }
	

	for i := 1; i < n; i++ {
		for j := i - 1; j >= 0; j-- {
			if nums[j] < nums[i] {
				dp[i] = max(dp[i], dp[j]+1)
			} 
		}
	}

	ret := dp[0]
	for i := 1; i < n; i++ {
		ret = max(ret, dp[i])
	}
	return ret
}

func max(i0, i1 int) int {
	if i0 > i1 {
		return i0
	}
	return i1
}

```