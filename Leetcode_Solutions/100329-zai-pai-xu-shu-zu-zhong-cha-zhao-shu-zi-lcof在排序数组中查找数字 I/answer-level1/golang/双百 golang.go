折半查找找到某一个target的位置，然后根据数组的排序特性向前，向后查找，直接return

```
func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1
	middle := (left + right) / 2
	count := 0
	for left <= right {
		if nums[middle] == target {
			count++
			for i := middle + 1; i < len(nums); i++ {
				if nums[i] == target {
					count++
				} else {
					break
				}
			}

			for i := middle - 1; i >= 0; i-- {
				if nums[i] == target {
					count++
				} else {
					break
				}
			}

			return count
		}

		if nums[middle] > target {
			right = middle - 1
		} else {
			left = middle + 1
		}
		middle = (left + right) / 2
	}

	return count
}
```
