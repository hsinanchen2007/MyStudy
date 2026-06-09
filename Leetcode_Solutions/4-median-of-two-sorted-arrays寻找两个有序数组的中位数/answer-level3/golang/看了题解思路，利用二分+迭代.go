### 解题思路
此处撰写解题思路

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	m, n := len(nums1), len(nums2)
	left, right := (m+n+1)/2,
		(m+n+2)/2
	return float64(findKth(nums1, 0, m-1, nums2, 0, n-1, left)+
		findKth(nums1, 0, m-1, nums2, 0, n-1, right)) / 2
}

func findKth(nums1 []int, start1, end1 int, nums2 []int, start2, end2 int, k int) int {
	len1, len2 := end1-start1+1, end2-start2+1
	if len1 > len2 {
		return findKth(nums2, start2, end2, nums1, start1, end1, k)
	}
	if len1 == 0 {
		return nums2[start2+k-1]
	}

	if k == 1 {
		return Min(nums1[start1], nums2[start2])
	}

	i, j := start1+Min(len1, k/2)-1,
		start2+Min(len2, k/2)-1

	if nums1[i] < nums2[j] {
		return findKth(nums1, i+1, end1, nums2, start2, end2, k-(i-start1+1))
	} else {
		return findKth(nums1, start1, end1, nums2, j+1, end2, k-(j-start2+1))
	}
}

func Min(x, y int) int {
	if x > y {
		return y
	}
	return x
}
```