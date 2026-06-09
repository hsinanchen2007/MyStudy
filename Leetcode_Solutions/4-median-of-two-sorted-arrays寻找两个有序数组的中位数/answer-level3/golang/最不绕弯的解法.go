看到两个有序数组，第一想法：归并
看到时间复杂度，第一想法：二分
那么顺着往下想：通过二分实现两个数组的合并，即可直接得出中位数
实现后优化思路：
1. 我们只需要找到 中位下标 即可，没必要真的初始化一个len(nums1)+len(nums2)的数组，然后把元素复制进去
2. 通过下标，可以去掉一些无用的递归

```
func lessThan(nums []int, val int) int {
	if len(nums) == 0 {
		return 0
	}
	from := 0
	to := len(nums) - 1
	for {
		if from == to {
			break
		}
		midIdx2 := (from + to) / 2
		if nums[midIdx2] < val {
			from = midIdx2 + 1
		} else {
			to = midIdx2
		}
	}
	if nums[from] < val {
		return from + 1
	}
	return from
}

type context struct {
	Idx1    int
	Idx2    int
	Num1    int
	Num2    int
	HasNum1 bool
	HasNum2 bool
}

// from表示，从合并数组的什么索引位置开始保存nums1和nums2的合并结果，因为不需要真的合并，所以只需要一个偏移量
func combine(nums1 []int, nums2 []int, from int, ctx *context) {
	nums1len := len(nums1)
	nums2len := len(nums2)
	if nums1len > nums2len {
		nums1, nums2 = nums2, nums1
		nums1len, nums2len = nums2len, nums1len
	}

	if nums1len == 0 {
		if nums2len > 0 {
			if from <= ctx.Idx1 && from+nums2len > ctx.Idx1 {
				ctx.Num1 = nums2[ctx.Idx1-from]
				ctx.HasNum1 = true
			}
			if from <= ctx.Idx2 && from+nums2len > ctx.Idx2 {
				ctx.Num2 = nums2[ctx.Idx2-from]
				ctx.HasNum2 = true
			}
		}
		return
	}

	mid := (nums1len - 1) / 2
	left := lessThan(nums2, nums1[mid])
	idx := from + mid + left
	if idx == ctx.Idx1 {
		ctx.Num1 = nums1[mid]
		ctx.HasNum1 = true
	}
	if idx == ctx.Idx2 {
		ctx.Num2 = nums1[mid]
		ctx.HasNum2 = true
	}
	if ctx.HasNum1 && ctx.HasNum2 {
		return
	}
	if mid > 0 || left > 0 {
		do := (!ctx.HasNum1 && from <= ctx.Idx1 && from+mid+left > ctx.Idx1) || (!ctx.HasNum2 && from <= ctx.Idx2 && from+mid+left > ctx.Idx2)
		if do {
			combine(nums1[0:mid], nums2[0:left], from, ctx)
			if ctx.HasNum1 && ctx.HasNum2 {
				return
			}
		}
	}
	do := (!ctx.HasNum1 && from+mid+1+left <= ctx.Idx1) || (!ctx.HasNum2 && from+mid+1+left <= ctx.Idx2)
	if do {
		combine(nums1[mid+1:], nums2[left:], from+mid+1+left, ctx)
	}

	return
}
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	total := len(nums1) + len(nums2)
	idx := (total - 1) / 2
	ctx := context{
		Idx1:    idx,
		Idx2:    idx,
		Num1:    0,
		Num2:    0,
		HasNum1: false,
		HasNum2: false,
	}
	if total%2 == 0 {
		ctx.Idx2 = idx + 1
	}
	combine(nums1, nums2, 0, &ctx)
	return float64(ctx.Num1+ctx.Num2) / 2
}
```
