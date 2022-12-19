### 解题思路
熟悉 golang 的语法和包,这道题很简单

首先是切片语法, append 第二个参数应为数组中的元素, 用 ... 将 nums2 的每个元素传入

golang 标准库 sort 包 已经对 []int 实现了 Ints 方法 排序即可

### 代码

```golang
func merge(nums1 []int, m int, nums2 []int, n int)  {
    nums1 = append(nums1[:m], nums2...)
    sort.Ints(nums1)
}
```