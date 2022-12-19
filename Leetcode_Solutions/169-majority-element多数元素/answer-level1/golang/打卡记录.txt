1. 哈希表
```
func majorityElement(nums []int) int {
	m := make(map[int]int)
	var max int
	for _, v := range nums {
		m[v] = m[v] + 1
		if m[v] > len(nums)/2 {
			max = v
			break
		}
	}
	return max
}
```
2. 排序法
```
func majorityElement(nums []int) int {
	sort.Ints(nums)
	return nums[len(nums)/2]
}
```
3. 摩尔排序
```
func majorityElement(nums []int) int {
	var (
		k     = nums[0]
		count = 1
	)
	for i := 1; i < len(nums); i++ {
		if count == 0 {
			k = nums[i]
			count = 1
		} else if nums[i] == k {
			count++
		} else {
			count--
		}
	}
	return k
}
```