### 解题思路
从前往后比较时移动元素会很麻烦

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
	var i, j = m -1, n - 1

	for k := m + n - 1; k >= 0; k-- {
		if j < 0 || (i >= 0 && nums1[i] > nums2[j]) {
			nums1[k] = nums1[i]
			i--
		} else {
			nums1[k] = nums2[j]
			j--
		}
	}
}
```