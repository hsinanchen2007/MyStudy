```
func mergeKLists(lists []*ListNode) *ListNode {
	var nums []int
	for k, _ := range lists {
		cur := lists[k]
		for cur != nil {
			nums = append(nums, cur.Val)
			cur = cur.Next
		}
	}
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	var res *ListNode
	for _, v := range nums {
		res = &ListNode{Val: v, Next: res}
	}
	return res
}
```
