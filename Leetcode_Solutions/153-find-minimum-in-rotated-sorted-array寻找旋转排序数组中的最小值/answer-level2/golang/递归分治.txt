	return findMinRec(nums, 0, len(nums)-1)
# 递归分治求解子序列最小值

### 解题思路

根据输入数组曾经排序过的特性，去寻找子字数组的最小值。
有以下情况：

* 子数组只有一个元素，那么最小值就是这个元素。
* 子数组有两个元素，返回这两个元素之间的最小值。
* 子数组有超过两个元素，检查收尾元素是否是排序过的，如果排序过，首就是最小元素。
* 子数组没有排序，那么递归分治求解。

### 代码

```golang
func findMin(nums []int) int {
	return findMinRec(nums, 0, len(nums)-1)
}

func findMinRec(nums []int, l, r int) int {
	// Only has 1 or 2 element
	if l == r {
		return nums[l]
	}

	if l+1 == r {
		return min(nums[l], nums[r])
	}

	// the subarray is sorted
	if nums[l] < nums[r] {
		return nums[l]
	}

	// divide and conquer
	mid := l + (r-l)/2
	return min(findMinRec(nums, l, mid-1), findMinRec(nums, mid, r))
}

func min(a, b int) int {
	if a > b {
		return b
	} else {
		return a
	}
}
```