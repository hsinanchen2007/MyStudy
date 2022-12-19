```
func kthToLast(head *ListNode, k int) int {
	nums := make([]int, 0)
	for ; head != nil; head = head.Next {
		nums = append(nums, head.Val)
	}
	return nums[len(nums)-k]
}
```
