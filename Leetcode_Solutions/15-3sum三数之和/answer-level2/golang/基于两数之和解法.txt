这题做的，费死个劲了，提交了n次终于对了。
时间复杂度  O(n*n)   (不会写n方。好尴尬 -_-!)


```
func threeSum(nums []int) [][]int {
	res := [][]int{}
	sort.Ints(nums)  //调用系统排序方法排序
	for i := 0; i < len(nums)-2; i++ {
		if i-1 >= 0 && nums[i] == nums[i-1] { //去重处理
			continue
		}
		tmp := twoSum(nums[i+1:], -nums[i])
		if tmp != nil {
			for _, t := range tmp {
				t = append(t, nums[i])
				res = append(res, t)
			}
		}
	}
	return res
}

func twoSum(nums []int, target int) [][]int {
	has := make(map[int]bool)
	drop := make(map[int]bool)
	res := [][]int{}
	for i := 0; i < len(nums); i++ {
		if has[target-nums[i]] {
			if drop[target-nums[i]] == false {  //去重处理
				res = append(res, []int{target - nums[i], nums[i]})
				drop[target-nums[i]] = true
			}
		} else {
			has[nums[i]] = true
		}
	}
	return res
}
```

