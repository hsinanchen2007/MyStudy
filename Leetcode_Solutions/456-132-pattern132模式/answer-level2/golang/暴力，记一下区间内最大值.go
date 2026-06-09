### 解题思路
暴力，记一下区间内最大值

### 代码

```golang
func find132pattern(nums []int) bool {
	for i := range nums {
		prev := nums[i]
		for j := i + 1; j < len(nums); j++ {
			prev = max(prev, nums[j])
			if nums[i] < nums[j] && nums[j] < prev {
				return true
			}
		}
	}
	return false
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

```