### 解题思路

对数组排序之后，用同时遍历两个数组，把相同元素放在第三个数组中，直到一个数组遍历完，结束。

### 代码

```golang
func intersect(nums1 []int, nums2 []int) []int {
	sort.Ints(nums1)
	sort.Ints(nums2)
	result := []int{}
	i,j := 0,0
	for i < len(nums1) && j < len(nums2) {
		if nums1[i] < nums2[j] {
				i++
		}else if nums1[i] > nums2[j] {
				j++
		}else {
				result = append(result,nums1[i])
				i++
				j++
		}
	}
	return result
}
```