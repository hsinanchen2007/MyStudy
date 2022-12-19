### 解题思路
此处撰写解题思路

### 代码

```golang
func intersection(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	s1, s2, l1, l2 := 0, 0, len(nums1), len(nums2)
	var data []int
	m := map[int]bool{}
	for s1 < l1 && s2 < l2 {
		if m[nums1[s1]] {
			s1++
			continue
		}
		if m[nums2[s2]] {
			s2++
			continue
		}
		if nums1[s1] == nums2[s2] {
			data = append(data, nums1[s1])
			m[nums1[s1]] = true
			s2++
			s1++
		} else if nums1[s1] > nums2[s2] {
			s2++
		} else {
			s1++
		}
	}
	return data
}
```