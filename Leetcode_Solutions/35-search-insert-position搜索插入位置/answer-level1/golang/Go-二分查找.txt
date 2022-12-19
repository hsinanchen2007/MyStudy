基础二分查找
```go
func searchInsert(nums []int, target int) int {
	l := len(nums)
	i, j := 0, l - 1
	if nums[i] >= target {
		return 0
	}
	if nums[j] < target {
		return l
	}
	if nums[j] == target {
		return j
	}
	for i < j {
		t := (i + j) / 2
		if nums[t] == target {
			return t
		} else if target < nums[t] {
			j = t
		} else if nums[t] < target {
			i = t
		}
        if i + 1 == j {
            return j
        }
	}
	return i
}
```
