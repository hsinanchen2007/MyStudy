```go
func twoSum(nums []int, target int) []int {
	tmpMap := make(map[int]int)

	for i, num := range nums {
		if v, isExist := tmpMap[target-num]; isExist {
			return []int{v, i}
		}

		tmpMap[num] = i
	}

	return []int{}
}
```

