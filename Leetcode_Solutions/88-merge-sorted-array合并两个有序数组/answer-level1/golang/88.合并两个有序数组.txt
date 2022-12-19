### 解题思路
思路：双指针法 i->nums1,j->nums2 先把nums1拷贝一份，最终排序结果放入原nums1，否则会导致nums1被覆盖

### 代码

```golang
//思路：双指针法 i->nums1,j->nums2 先把nums1拷贝一份，最终排序结果放入原nums1，否则会导致nums1被覆盖
func merge(nums1 []int, m int, nums2 []int, n int)  {
	bak := make([]int, m)
	copy(bak, nums1)

	var i,j,k = 0,0,0
	for i < m && j < n {
		if bak[i] <= nums2[j] {
			nums1[k] = bak[i]
			i++
		}else {
			nums1[k] = nums2[j]
			j++
		}
		k++
	}
	if i >= m {
		for j < n {
			nums1[k] = nums2[j]
			k++
			j++
		}
	}else {
		for i < m {
			nums1[k] = bak[i]
			k++
			i++
		}
	}
}
```