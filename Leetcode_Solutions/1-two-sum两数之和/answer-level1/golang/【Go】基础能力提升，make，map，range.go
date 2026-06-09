```
func twoSum(nums []int, target int) []int {
	diff := make(map[int]int)
	for i, num := range nums {
		if j, ok := diff[target - num];ok {
			return []int{i, j}
		}
		diff[num] = i
	}
	return nil
}
```
