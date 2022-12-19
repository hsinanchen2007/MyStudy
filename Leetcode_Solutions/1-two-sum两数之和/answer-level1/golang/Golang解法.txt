// 时间换空间
```golang
func twoSum(nums []int, target int) []int {
	ret := []int{}
	for idx1, val1 := range nums {
		for idx2 := idx1 + 1; idx2 < len(nums); idx2++ {
			val2 := nums[idx2]
			if val1+val2 == target {
				ret = []int{idx1, idx2}
			}
		}
	}
	return ret
}
```

// 空间换时间
```golang
func twoSum(nums []int, target int) []int {
	var ret []int
	numToIndex := map[int]int{}
	for idx, num := range nums {
		another := target - num
		if anotherIdx, ok := numToIndex[another]; ok {
			ret = []int{anotherIdx, idx}
			break
		}
		numToIndex[num] = idx
	}
	return ret
}
```