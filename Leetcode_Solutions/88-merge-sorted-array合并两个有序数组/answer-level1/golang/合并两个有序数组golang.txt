### 解题思路
此处撰写解题思路

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
  for i, j := m+n-1, m-1; i >= 0 && j >= 0; {
		nums1[i] = nums1[j]
		i--
		j--
	}

	var (
		k    = n
		i, j = 0, 0
	)
	for ; i < m+n && j < n && k < m+n; i++ {
		if nums1[k] <= nums2[j] {
			nums1[i] = nums1[k]
			k++
		} else {
			nums1[i] = nums2[j]
			j++
		}
	}

	for k < m+n {
		nums1[i] = nums1[k]
		i++
		k++
	}

	for j < n {
		nums1[i] = nums2[j]
		i++
		j++
	}
}
```