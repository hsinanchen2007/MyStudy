 将num2的元素写入num1的空位后重新排序。
```
执行用时 : 0 ms, 在Merge Sorted Array的Go提交中击败了100.00% 的用户
内存消耗 : 3.7 MB, 在Merge Sorted Array的Go提交中击败了45.45% 的用户
```
```go []
func merge(nums1 []int, m int, nums2 []int, n int) {
	for i := m; i < m+n; i++ {
		nums1[i] = nums2[i-m]
	}
	sort.Ints(nums1)
}