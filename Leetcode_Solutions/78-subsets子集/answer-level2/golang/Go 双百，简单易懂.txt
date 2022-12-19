```
func subsets(nums []int) (rst [][]int) {
	if len(nums) == 0 {
		return [][]int{{}}
	}
	if len(nums) == 1 {
		return [][]int{nums, {}}
	}

	subRst := subsets(nums[1:])
	for _, num := range subRst {
		rst = append(rst, num)                                      // 没我
		rst = append(rst, append(num[:len(num):len(num)], nums[0])) // 有我
	}
	return
}
```
