1. 将目标元素（nums[i]）的值作为下标，对目标元素的值改为0。
2. 遍历数组，将不为0的元素的下标，加到结果集里，得到结果。

```golang
func findDisappearedNumbers(nums []int) []int {
	for i := 0; i < len(nums); i++ {
		if nums[i] != 0{
			pushTargetToZero(nums, nums[i] - 1)
		}
	}

	var result []int
	for i := 0;i < len(nums); i++ {
		if nums[i] != 0 {
			result = append(result, i + 1)
		}
	}
	return result
}

func pushTargetToZero(nums []int, target int) {
	if nums[target] == 0 {
		return
	} else {
		temp := nums[target]
		nums[target] = 0
		pushTargetToZero(nums, temp - 1)
	}
}
```

