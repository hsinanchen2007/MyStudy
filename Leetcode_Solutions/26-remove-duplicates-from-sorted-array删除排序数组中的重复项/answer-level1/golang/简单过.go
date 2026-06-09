### 解题思路
一次遍历，时间复杂度O(n)，空间复杂度O(1)。
变量数已经不能再少了，为何还消耗这么多内存？难度是因为len<2的边界判断？

执行用时 :8 ms, 在所有 Go 提交中击败了94.17% 的用户
内存消耗 :4.6 MB, 在所有 Go 提交中击败了12.90%的用户

### 代码

```golang
func removeDuplicates(nums []int) int {
	if len(nums) < 2 {
		return len(nums)
	}
	end := 1 //无重复的后一位索引
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[end] = nums[i]
			end++
		}
	}
	return end //等价于len(nums[:end])
}
```