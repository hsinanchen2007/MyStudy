思路： 题目要求O(log n)时间复杂度和 O(1)空间复杂度，所以采用二分搜索法。

```
执行用时 :12 ms, 在所有 Go 提交中击败了61.76%的用户
内存消耗 :4.3 MB, 在所有 Go 提交中击败了9.09%的用户
```
```Go []
func singleNonDuplicate(nums []int) int {
	var i int
	for {
		if len(nums) <= 2 {
			return nums[0]
		}
		i = len(nums) / 2
		if i%2 == 1 {
			i++
		}
		if nums[i-1] != nums[i-2] {
			nums = nums[0:i]
		} else {
			nums = nums[i:]
		}
	}
}
```

[LeetCodeByGo: 更多LeetCode题库Go语言题解](https://github.com/mrandmrsbenben/LeetCodeByGo)