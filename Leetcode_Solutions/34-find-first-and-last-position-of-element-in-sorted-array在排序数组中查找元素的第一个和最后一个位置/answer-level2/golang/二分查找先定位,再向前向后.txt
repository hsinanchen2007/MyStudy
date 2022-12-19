### 解题思路
先用二分查找找到目标值在数组中的某一个索引,然后向前查找第一个出现的位置,向后查找最后一个出现的位置

### 代码

```golang
func searchRange(nums []int, target int) []int {
    low, high := 0, len(nums)-1

	index, first, last := -1, -1, -1
    var middle int
	// 二分查找
	for ; low <= high; {
		middle = low + ((high - low) >> 1)
		if nums[middle] > target {
			high = middle - 1
		} else if nums[middle] < target {
			low = middle + 1
		} else {
			// 找到目标值在数组中的某一个索引位置,注意此时并不知道该位置是否是第一次出现,或者是最后一次出现
			index = middle
			break
		}
	}

	// 未找到,则返回 -1, -1
	if index == -1 {
		return []int{first, last}
	}

	first, last = index, index

	// 向前寻找最早出现的位置
	for ; first != 0 && nums[first-1] == target; {
		first--
	}
	// 向后寻找最晚出现的位置
	for ; last != len(nums)-1 && nums[last+1] == target; {
		last++
	}

	return []int{first, last}
}
```