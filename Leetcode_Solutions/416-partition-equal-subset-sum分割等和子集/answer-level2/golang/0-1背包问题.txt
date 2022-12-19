## 题义分析

- 给定一个数组，问能不能把数组分成两个数组，使得两个数组中的元素和相同
- 先求出数组元素和sum，当sum为基数时，直接返回false
    - 当sum为偶数时，设num=sum/2。题目可以转化为：从数组中选择任意个数，使得选出来的数之和为num，数组中的数不能重复选择
    

## 动态规划三步曲

### 定义解

设dp[i][j]表示从数组nums[:j]中能否选出和为i的数字组合，则dp[num][len(nums)]

### 状态转移方程

1. 当i < nums[j]时，dp[i][j] = dp[i][j-1]
2. 当i>=nums[j]时，dp[i][j] = dp[i][j-1]||dp[i-nums[j]][j-1]

### 初始值

1. 当i==nums[0]时，dp[i][0] = true 
2. dp[0][j]=true

## 代码

    func canPartition(nums []int) bool {
    	if nums == nil {
    		return true
    	}
    	sum := 0
    	for _, num := range nums {
    		sum += num
    	}
    	if sum%2 == 1 {
    		return false
    	}
    	sum = sum / 2
    
    	n := len(nums)
    	dp := make([][]bool, sum+1)
    	for i := 0; i <= sum; i++ {
    		dp[i] = make([]bool, n)
    		if i == nums[0] {
    			dp[i][0] = true
    		}
    	}
    
    	for i:=0 ;i<n;i++{
    		dp[0][i] = true
    	}
    
    	for i := 0; i <= sum; i++ {
    		for j := 1; j < n; j++ {
    			dp[i][j] = dp[i][j-1]
    			if i >= nums[j] {
    				dp[i][j] = dp[i][j-1] || dp[i-nums[j]][j-1]
    			}
    		}
    	}
    	return dp[sum][n-1]
    }