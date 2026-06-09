//思路：自定义方法排序后，输出字符串即可
//位数不同时无法使用普通排序方法，比如9要放到10前面
//两个数字拼起来时位数一样，可以比较大小，以此写出排序方法
func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		n1 := strconv.Itoa(nums[i]) + strconv.Itoa(nums[j])
		n2 := strconv.Itoa(nums[j]) + strconv.Itoa(nums[i])
		//n1与n2拼起来时可能越界，需要用到大数比较大小的方法
		//也可以使用go自带的big库，不过此处不需要做运算，直接比是最简单的
		for m := range n1 {
			if n1[m] > n2[m] {
				return true
			}
			if n2[m] > n1[m] {
				return false
			}
		}
		return true
	})
	s := ""
	for _, n := range nums {
		//注意特殊数字0，用例会提醒你的
		if s == "" && n == 0 {
			continue
		}
		s += strconv.Itoa(n)
	}
	if s == "" {
		s = "0"
	}
	return s
}