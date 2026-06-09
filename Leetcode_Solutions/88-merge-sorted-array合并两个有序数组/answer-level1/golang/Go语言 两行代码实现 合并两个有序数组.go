![88合并两个有序数组.png](https://pic.leetcode-cn.com/78154653223ebc4dff0b48e5243f8604f10fc86988a7e874e08a3afcde6c31cd-88%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84.png)
```
func merge(nums1 []int, m int, nums2 []int, n int) {
    nums1 = append(nums1[:m], nums2[:n]...)
    sort.Ints(nums1)
}
```
