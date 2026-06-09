# 直接按题目要求一顿揍

```golang
func minSubsequence(nums []int) []int {
	var res []int
	sort.Ints(nums)
	sum := 0
	for _, n := range nums {
		sum += n
	}
	counter := 0
	i := len(nums)
	half := sum / 2

	for counter <= half {
		i--
		counter += nums[i]
		res = append(res, nums[i])
	}
	return res
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
