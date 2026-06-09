先用标准库对两个数组进行排序，然后循环长度较长的数组，查找是否有与长度短的数组相等的数值。

```
执行用时 : 8 ms, 在Intersection of Two Arrays II的Go提交中击败了94.62% 的用户
内存消耗 : 4.7 MB, 在Intersection of Two Arrays II的Go提交中击败了84.03% 的用户
```
```Go []
func intersect(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	nums := make([]int, 0)
	if len(nums1) < len(nums2) {
		nums1, nums2 = nums2, nums1
	}
	for i, j := 0, 0; i < len(nums1) && j < len(nums2); i++ {
		if nums1[i] > nums2[j] {
			for {
				j++
				if j == len(nums2) || nums1[i] <= nums2[j] {
					break
				}
			}
			if j == len(nums2) {
				break
			}
		}
		if nums1[i] == nums2[j] {
			nums = append(nums, nums1[i])
			j++
		}
	}
	return nums
}
