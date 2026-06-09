### 解题思路

每移动一次，n-1个元素-1，就等于1个元素+1。依次用每个元素减去最小的元素的差相加即可。

### 代码

```golang
func minMoves(nums []int) int {
	min := nums[0]
	for i :=1;i < len(nums);i++ {
		if nums[i] < min {
			min = nums[i]
		}
	}
	res := 0
	for i := 0;i < len(nums);i++ {
		res += nums[i] - min
	}
	return res
}
```