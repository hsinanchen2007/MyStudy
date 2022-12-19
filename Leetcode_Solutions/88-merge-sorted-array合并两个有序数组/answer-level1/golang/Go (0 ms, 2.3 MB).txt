### 解题思路

从大到小向前排序

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    m,n = m - 1,n - 1
	z := m + n + 1
	for m >= 0 || n >= 0 {
		if m < 0 {
			nums1[z] = nums2[n]
			n--
		} else if n < 0 {
			nums1[z] = nums1[m]
			m--
		} else if nums1[m] > nums2[n] {
			nums1[z] = nums1[m]
			m--
		} else {
			nums1[z] = nums2[n]
			n--
		}
		z--
	}
}
```