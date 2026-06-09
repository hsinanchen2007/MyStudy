```
func twoSum(nums []int, target int) []int {
	nummap := make(map[int]int, len(nums)+1)
	result := make([]int, 2)
	for k, v := range nums {
		ek, ok1 := nummap[v]
		if ok1 {
			if v*2 == target {
				fmt.Println("hello")
				result = []int{ek, k}
				return result
			}
		}
		nummap[v] = k
	}

	for kk, vv := range nums {
		res := target - vv

		ha, ok := nummap[res]
		if ok {
			if kk != ha {
				result = []int{kk, ha}
				break
			}

		}
	}
	return result
}
```
