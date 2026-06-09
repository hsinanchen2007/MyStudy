
```go

// 四指针 基于三数之和演进
func fourSum(nums []int, target int) [][]int {
    
    
	l := len(nums)
	res := make([][]int, 0)
	if l<4 {return res}

	// a,b,c,d四指针

	sort.Ints(nums)

	var sum int
	for a:=0; a<l-3; a++ {	// 最左指针
		if a>0 && nums[a]==nums[a-1] {continue}		// 剔除重复项

		for b:=a+1; b<l-2; b++ {	// 次左指针
			if b>a+1 && nums[b]==nums[b-1] {continue}	// 剔除重复项

			// 内层双指针
			for c, d := b+1, l-1; c<d; {
				sum = nums[a] + nums[b] + nums[c] + nums[d]
				switch {
				case sum > target:
					d--
					for c<d && nums[d]==nums[d+1] {d--}		// 剔除重复项
				case sum < target:
					c++
					for c<d && nums[c]==nums[c-1] {c++} 	// 剔除重复项
				default:	// sum = target
					res = append(res, []int{nums[a], nums[b], nums[c], nums[d]})	// 找到可行解且不重复
					d--
					for c<d && nums[d]==nums[d+1] {d--}		// 剔除重复项
					c++
					for c<d && nums[c]==nums[c-1] {c++} 	// 剔除重复项
				}
			}
		}
	}

	return res
}


// 优化四指针
func fourSum(nums []int, target int) [][]int {
    
    
	l := len(nums)
	res := make([][]int, 0)
	if l<4 {return res}

	// a,b,c,d四指针

	sort.Ints(nums)

	var sum int
	for a:=0; a<l-3; a++ {	// 最左指针
		if a>0 && nums[a]==nums[a-1] {continue}		// 剔除重复项

		// 处理min/max/target
		min1 := nums[a] + nums[a+1] + nums[a+2] + nums[a+3]
		if min1>target {break}		// 此时min1是绝对最小，所以，如果target<min1，就break，因为不可能找到了
		max1 := nums[a] + nums[l-3] + nums[l-2] + nums[l-1]
		if max1<target {continue}	// 此时max1不是绝对最大，所以进入下一轮循环

		for b:=a+1; b<l-2; b++ {	// 次左指针
			if b>a+1 && nums[b]==nums[b-1] {continue}	// 剔除重复项

			// 处理min/max/target
			min2 := nums[a] + nums[b] + nums[b+1] + nums[b+2]
			if min2>target {break}		// 跳出
			max2 := nums[a] + nums[b] + nums[l-2] + nums[l-1]
			if max2<target {continue} 	// 下一轮循环

			// 内层双指针
			for c, d := b+1, l-1; c<d; {
				sum = nums[a] + nums[b] + nums[c] + nums[d]
				switch {
				case sum > target:
					d--
					for c<d && nums[d]==nums[d+1] {d--}		// 剔除重复项
				case sum < target:
					c++
					for c<d && nums[c]==nums[c-1] {c++} 	// 剔除重复项
				default:	// sum = target
					res = append(res, []int{nums[a], nums[b], nums[c], nums[d]})	// 找到可行解且不重复
					d--
					for c<d && nums[d]==nums[d+1] {d--}		// 剔除重复项
					c++
					for c<d && nums[c]==nums[c-1] {c++} 	// 剔除重复项
				}
			}
		}
	}

	return res
}
```