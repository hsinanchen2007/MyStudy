本题关键之处（完整代码见文末）：

- 直接利用map特性求解
- 进一步思考如何利用**排序数组**的特性

![image.png](https://pic.leetcode-cn.com/3548d8ee1b46e28d7909023ce0eb906f20d3126321fd8fd8b54acc35b1314baf-image.png)


```go []
func intersect(nums1 []int, nums2 []int) []int {
	i, j, k := 0, 0, 0
	sort.Ints(nums1)
	sort.Ints(nums2)
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] > nums2[j] {
			j++
		} else if nums1[i] < nums2[j] {
			i++
		} else {
			nums1[k] = nums1[i]
			i++
			j++
			k++
		}
	}
	return nums1[:k]
}
```