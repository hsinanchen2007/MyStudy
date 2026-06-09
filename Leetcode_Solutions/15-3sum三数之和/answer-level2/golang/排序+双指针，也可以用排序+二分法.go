排序+双指针，排序后遍历 数组第i个数为一个定值，0-nums[i]然后再后面的数组求两位数和，双指针，left=i+1,right=len(nums)-1，如果nums[i] + nums[left]+nums[right] > 0 则right指针左移，即--，小于0的话left指针右移，即++，=0的话则i，left,right即为一个解，同时left++，right++，寻找下一个值，由于数组中会有重复数字，所以每一个解加到结果集中需要去重
```
func threeSum(nums []int) [][]int {
	//双指针法
	quickSort(nums)
	result := [][]int{}
	for i:=0;i<len(nums)-1;i++ {
		target := 0-nums[i]
		twoSum(nums, i, i+1,len(nums)-1,target,&result)
	}
	return result
}

func twoSum(nums []int, k,left,right,target int, r *[][]int) {
	if left >= right {
		return
	}
	if nums[left] + nums[right] == target {
		addToResult(r, []int{nums[k], nums[left], nums[right]})
		right--
		left++
	}else if nums[left] + nums[right] > target {
		right--
	}else {
		left++
	}
	twoSum(nums, k, left, right, target, r)
}

//去重
func addToResult (r *[][]int, a[]int)  {
	dupli := false
	for _, v := range *r {
		if v[0] == a[0] && v[1] == a[1] && v[2] == a[2] {
			dupli = true
		}
	}
	if !dupli {
		*r = append(*r, a)
	}
}
//快排
func quickSort(r []int) {
	if len(r) <= 1 {
		return
	}
	count := len(r)
	q := r[count-1]
	i := 0
	for j, v := range r {
		if j == count-1 {
			break
		}
		if v < q {
			r[i], r[j] = r[j], r[i]
			i++
		}
	}
	r[i], r[count-1] = q, r[i]
	quickSort(r[:i])
	quickSort(r[i+1:])
}
```
