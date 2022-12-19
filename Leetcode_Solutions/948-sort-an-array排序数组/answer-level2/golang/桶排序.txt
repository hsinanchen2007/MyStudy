题目定义了数组长度在一定范围内，那么，直接上桶排序吧
```golang
func sortArray(nums []int) []int {
	tmp := make([]int, 100001)
	for _, v := range nums {
		tmp[v+50000]++
	}
	var index int
	for i, v := range tmp {
		for x := 0; x < v; x++ {
			nums[index] = i - 50000
			index++
		}
	}
	return nums
}
```