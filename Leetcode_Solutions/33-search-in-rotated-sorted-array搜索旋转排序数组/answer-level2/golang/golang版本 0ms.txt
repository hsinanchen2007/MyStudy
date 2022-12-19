#### 33.搜索旋转排序数组
题意：一段有序数组，从某个节点旋转，即变为两段有序数组，要求在log(n)查询指定元素

解题思路：常规思路，看题就想到二分，先找出拐点，数组分为两段，左段比右端都要大，即左段第一个元素比右段最后一个元素都要大，target和左段第一个元素比较，如果相等就直接返回，大于的话在左段查询，小于的话在右端查询

1A 0ms

```
func bsearch(nums []int, v int, left int, right int) int {
	if left > right {
		return -1
	}
	mid := (left + right) >> 1
	//fmt.Printf("left:%d right:%d mid:%d v:%d\n", left, right, mid, nums[mid])
	if nums[mid] == v {
		return mid
	} else if nums[mid] < v {
		return bsearch(nums, v, mid+1, right)
	} else {
		return bsearch(nums, v, left, mid-1)
	}
}

func search(nums []int, target int) int {
	count := len(nums)
	turnIndex := findTurnIndex(nums)
	//fmt.Printf("count:%d\n", count)
	//fmt.Printf("turnIndex:%d\n", turnIndex)
	result := -1
	if turnIndex == 0 {
		result = bsearch(nums, target, 0, count-1)
	} else {
		//数组分为两段有序数组,左端的数组比右端的数组值要大
		if target < nums[0] {
			//比左端最小还要小,右端查找
			result = bsearch(nums, target, turnIndex, count-1)
		} else if target > nums[0] {
			//比左端最小大,左端查找
			result = bsearch(nums, target, 0, turnIndex-1)
		} else {
			result = 0
		}
	}

	return result
}

func findTurnIndex(nums []int) int {
	turnIndex := 0
	count := len(nums)
	for i := 1; i < count; i++ {
		if nums[i] < nums[i-1] {
			turnIndex = i
		}
	}
	return turnIndex
}
```