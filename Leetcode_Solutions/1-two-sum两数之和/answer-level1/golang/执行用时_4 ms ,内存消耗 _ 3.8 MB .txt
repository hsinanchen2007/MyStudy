```
func twoSum(nums []int, target int) []int {
   	m:=make(map[int]int)

	for k, v := range nums {
		if tI,ok := m[target-v];ok&&tI!=k{
			return []int{k,tI}
		}
		m[v]=k
	}
	return []int{}
}
```
