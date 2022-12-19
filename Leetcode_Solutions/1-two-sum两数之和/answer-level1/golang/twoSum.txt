```
func twoSum(nums []int, target int) []int {
	indexs := make(map[int]int, len(nums))
	for i, v := range nums {
		if j, ok := indexs[target-v]; ok {
			return []int{j, i}
		}
		indexs[v] = i
	}
	return []int{}
}
```
