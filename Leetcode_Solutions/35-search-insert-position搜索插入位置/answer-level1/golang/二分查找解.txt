![image.png](https://pic.leetcode-cn.com/de769f9de97a7cd997871fa104efc20b88b5c3667725c8f7a9f6de6864bc2e58-image.png)

```
func searchInsert(nums []int, target int) int {
    if target == 0 {
		return 0
	}
	var left = 0
	var right = len(nums)
	var mid = 0
	for left < right {
		mid = (left + right) / 2
		//fmt.Println(mid)
		if nums[mid] > target {
			mid--
			right = mid
		} else if nums[mid] < target {
			mid++
			left = mid
		} else {
			return mid
		}
	}

	if mid < 0 {
		return 0
	}

	if mid < len(nums) && nums[mid] < target {
		return mid + 1
	}
	return mid
}
```
