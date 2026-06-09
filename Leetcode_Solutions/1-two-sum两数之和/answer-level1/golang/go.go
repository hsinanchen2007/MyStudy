
结合各路大神思路，但是这样使用var声明变量提示答案错误，放入函数体内正常.是因为内部编译问题吗，还是代码问题？
```
var (
	rul []int
	tmp map[int]int
)

func twoSum(nums []int, target int) []int {
	size := len(nums)
	for i, v := range nums {
		for j := i + 1; j < size; j++ {
			if v + nums[j] == target {
				rul = append(rul, i, j)
			}
		}
	}
	return rul
}

func twoSum2(nums []int, target int) []int {
	tmp = make(map[int]int)
	for i, v := range nums {
		tmp[v] = i
	}

	for i, v := range nums {
		j, ok := tmp[target - v]
		if ok && j != i {
			rul = append(rul, i, j)
			break
		}
	}
	return rul
}

func twoSum3(nums []int, target int) []int {
	tmp = make(map[int]int)
	for i, v := range nums {
		if j, ok := tmp[target - v]; ok {
			rul = append(rul, j, i)
			break
		}
		tmp[v] = i
	}
	return rul
}
```