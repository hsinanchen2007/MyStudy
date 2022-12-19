瞎写的
```
func nextGreaterElement(nums1 []int, nums2 []int) []int {
	Map := make(map[int]int)
	for i, v := range nums2 {
		Map[v] = i
	}
	for i, v1 := range nums1 {
		for _, v2 := range nums2[Map[v1]:] {
			if v2 > v1 {
				nums1[i] = v2
				goto P
			}
		}
		nums1[i] = -1
	P:
	}
	return nums1
}
```
