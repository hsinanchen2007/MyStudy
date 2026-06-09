### 解题思路
因为是一个区间范围，不是找到就可以退出循环，需要找到边界

### 代码

```golang
func searchRange(nums []int, target int) []int {
	if len(nums) < 1 {
		return []int{-1, -1}
	}

	leftIndex := -1
	rightIndex := -1

	// 找左索引
	left := 0
	right := len(nums) - 1
	for left <= right {
		middle := left + (right - left) / 2
		if nums[middle] == target {
			if middle - 1 < 0 || nums[middle - 1] < target { // 这里是关键
				leftIndex = middle
				break
			} else {
				right = middle - 1
			}
		} else if nums[middle] > target {
			right = middle - 1
		} else {
			left = middle + 1
		}
	}

	// 找右索引
	left = 0
	right = len(nums) - 1
	for left <= right {
		middle := left + (right - left) / 2
		if nums[middle] == target {
			if middle + 1 >= len(nums) || nums[middle + 1] > target { // 这里是关键
				rightIndex = middle
				break
			} else {
				left = middle + 1
			}
		} else if nums[middle] > target {
			right = middle - 1
		} else {
			left = middle + 1
		}
	}

	return []int{leftIndex, rightIndex}    
}
```