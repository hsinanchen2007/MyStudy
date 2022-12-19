- 别跟我说range，range会复制对象
```
func twoSum(nums []int, target int) []int {
	length := len(nums)
	m := make(map[int]int,length-1)
	for i := 0;i< length;i++{
		if v,ok := m[nums[i]];ok{
			return []int{v, i}
		}
		m[target-nums[i]] = i
	}
	return []int{}
}
```