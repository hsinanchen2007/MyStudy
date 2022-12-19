```
func findLeft(nums[]int,target int)int{
	left,right:=0,len(nums)-1
	var flag bool
	for left<=right{
		mid:=(left+right)/2
		fmt.Println(left,right,mid)
		if nums[mid]<target{
			left=mid+1
		}else if nums[mid]>target{
			right=mid-1
		}else{
			flag=true
			right=mid-1
		}
	}
	if flag{
		return right+1
	}else{
		return -1
	}
}
func findRight(nums []int, target int) int {
	left, right := 0, len(nums)-1
	var flag bool
	for left < right {
		mid := (left + right) / 2
		if nums[mid] < target {
			left=mid+1
		}else if nums[mid]>target{
			right=mid-1
		}else{
			flag=true
			left=mid+1
		}
	}
	if flag{
		return left-1
	}else{
		return -1
	}
}

//解法3:二分查找:找到最右数字
func searchRange(nums []int, target int) []int {
	return []int{findLeft(nums,target),findRight(nums,target)}
}
```