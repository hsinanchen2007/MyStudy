### 解题思路
最长上升子序列应该是动态规划里面比较经典的题目，不过因为我只简单了解过动态规划，所以转移方程还是没列出来，下面是我大概的思路：
1. 创建一个跟 nums 等长的数组 dp
2. dp[i] 存储的是索引小于 i 且对应元素小于 nums[i] 的元素的个数
3. 最后利用 sort 函数对 dp 进行排序
4. 返回 dp 的最后一个元素加一（因为上面在计算的时候都是不包含本身的，所以在返回的时候需要加 1）

### 代码

```golang
func lengthOfLIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	var dp = make([]int, len(nums))
	for i := 0; i < len(nums); i++ {
		var max int
		for j := i - 1; j >= 0; j-- {
			if nums[j] < nums[i]&&dp[j]+1>max {
				max = dp[j]+1
			}
		}
		dp[i] = max
	}
	sort.Ints(dp)
	return dp[len(nums)-1]+1
}
```