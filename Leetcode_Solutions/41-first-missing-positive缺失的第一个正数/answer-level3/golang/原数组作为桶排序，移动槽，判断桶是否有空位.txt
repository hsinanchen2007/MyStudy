### 解题思路
移动槽

### 代码

```golang
func moveSlot(nums []int, slot int, newVal int) {
	if slot >= len(nums) || slot < 0 {
		return
	}
	oldVal := nums[slot]
	if oldVal != newVal {
		nums[slot] = newVal
		moveSlot(nums, oldVal-1, oldVal)
	}
}

func firstMissingPositive(nums []int) int {
	for i:=0; i< len(nums); i++ {
		if nums[i] > len(nums) || nums[i] < 1 {
			nums[i] = 0
			continue
		}
		if nums[i] != i+1 {
			moveSlot(nums, i, 0)
		}
	}
	for i:=0; i < len(nums); i++ {
		if nums[i] == 0 {
			return i+1
		}
	}
	return len(nums)+1
}
```