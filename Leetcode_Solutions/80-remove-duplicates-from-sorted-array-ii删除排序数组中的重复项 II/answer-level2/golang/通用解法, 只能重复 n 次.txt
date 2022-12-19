//通用解法, 只能重复 n 次
```
func removeDuplicates(nums []int, n int) int {
	i, j := n, n
	for ; i < len(nums); i++ {
		if nums[i] != nums[j-n] {
			nums[j] = nums[i]
			j++
		}
	}
	return j
}
```