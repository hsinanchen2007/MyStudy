```
func findDuplicates(nums []int) []int {
	if len(nums) == 0 {return nums}
	sort.Ints(nums)
	arr := make([]int, 0)
	temp, num := nums[0], 1
	for i := 1; i < len(nums); i ++ {
		if nums[i] == temp {
			num ++
		} else {
			temp = nums[i]
			if num == 2 {
				arr = append(arr, nums[i - 1])
			}
			num = 1
		}
	}

    if num == 2 { arr = append(arr, nums[len(nums) - 1])}

	return arr
}
```
