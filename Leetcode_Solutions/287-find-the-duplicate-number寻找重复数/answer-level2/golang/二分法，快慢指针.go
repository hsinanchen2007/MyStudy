看题解做的二分，写一下理解，方便以后遇到类似的题：因为如果没有重复数字，那数组里面的数字就应该是1-n，直接二分1-n，得到mid值，遍历数组，如果mid值在数组中个数大于1直接返回mid，否则查看小于mid的只在数组的个数大于等于mid数的话，说明重复数字在mid的左边（即right = mid -1），反之在右边（left= mid+1），一次类推不停二分
********************
```
func findDuplicate(nums []int) int {
	left ,right := 1, len(nums)
	mid := left + (right-left)>>1
	for left <= right  {
		mid = left + (right-left)>>1
		if numCount(nums, mid) > 1 {
			return mid
		}else if lessNumCount(nums, mid) >= mid {
			right = mid-1
		}else {
			left = mid+1
		}
	}
	return mid
}

func numCount(nums []int, n int) int {
	count := 0
	for _,v := range nums {
		if v == n {
			count++
		}
	}
	return count
}

func lessNumCount(nums []int, n int) int {
	count := 0
	for _,v := range nums {
		if v < n {
			count++
		}
	}
	return count
}
```
*************

快慢指针
```
func findDuplicate(nums []int) int {
	s := nums[0]
	f := nums[nums[0]]
	for s != f  {
		s = nums[s]
		f = nums[nums[f]]
	}
	f = 0
	for s != f  {
		s = nums[s]
		f = nums[f]
	}
	return s
}
```

