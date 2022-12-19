### 解题思路
双指针归并两个有序数组成为最终有序，取中位数即可

### 代码

```golang
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	var midIndex int
	pos1, pos2 := 0, 0
	len1, len2 := len(nums1), len(nums2)
	mergeSortedList := make([]int, 0)
	for ; pos1 < len1 && pos2 < len2; {
		if nums1[pos1] <= nums2[pos2] {
			mergeSortedList = append(mergeSortedList, nums1[pos1])
			pos1 += 1
		} else {
			mergeSortedList = append(mergeSortedList, nums2[pos2])
			pos2 += 1
		}
	}
	if pos1 == len1 {
		mergeSortedList = append(mergeSortedList, nums2[pos2:]...)
	} else {
		mergeSortedList = append(mergeSortedList, nums1[pos1:]...)
	}
	if (len1 + len2) % 2 == 0 {
		midIndex = (len1 + len2) / 2
		return float64(mergeSortedList[midIndex-1] + mergeSortedList[midIndex]) / 2
	} else {
		midIndex = (len1 + len2) / 2
		return float64(mergeSortedList[midIndex])
	}
}
```