### 解题思路
此处撰写解题思路

### 代码

```golang
func search(nums []int, target int) int {
	if len(nums) == 0 {
		return -1
	}

	// 因为下面的判断都需要数组长度大于1，所以把数组长度为1、第一个元素相等的情况处理了
	if nums[0] == target {
		return 0
	} else if len(nums) == 1 {
		return -1
	}

	left := 0
	right := len(nums) - 1
	originFirst := 0
	for left <= right {
		middle := left + (right - left) / 2
		if middle + 1 >= len(nums) { // 注意这里的边界
			break
		} else if nums[middle] > nums[middle + 1] {
			originFirst = middle + 1
			break
		} else if nums[middle] >= nums[0] {
			left = middle + 1
		} else {
			right = middle - 1
		}
	}

	if target > nums[0] {
		left = 0
		right = (originFirst - 1 + len(nums)) % len(nums) // 防止originFirst为0时的右索引错误
	} else {
		left = originFirst
		right = len(nums) - 1
	}

	for left <= right {
		middle := left + (right - left) / 2
		if nums[middle] == target {
			return middle
		} else if nums[middle] > target {
			right = middle - 1
		} else {
			left = middle + 1
		}
	}

	return -1
}
```