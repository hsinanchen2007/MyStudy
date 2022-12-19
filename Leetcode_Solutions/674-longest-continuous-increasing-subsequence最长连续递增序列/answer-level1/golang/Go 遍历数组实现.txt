遍历数组，当前值同前值比较为递减时计算当前递增序列长度，超过最大值时当前长度为最大值，并以当前索引为起点重新计算递增长度直至数组末尾。

```
 执行用时 : 12 ms, 在Longest Continuous Increasing Subsequence的Go提交中击败了100.00% 的用户
 内存消耗 : 4.6 MB, 在Longest Continuous Increasing Subsequence的Go提交中击败了8.33% 的用户
```
```Go []
func findLengthOfLCIS(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	max := 0
	start := 0
	for i := 1; i < len(nums); i++ {
		if nums[i] <= nums[i-1] {
			if i-start > max {
				max = i - start
			}
			start = i
		} else if i == len(nums)-1 && i-start+1 > max {
			max = i - start + 1
		}
	}
	return max
}
