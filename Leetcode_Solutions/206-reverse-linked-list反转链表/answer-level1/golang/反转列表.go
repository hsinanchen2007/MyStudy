3个指针，一个保存当前，一个保存前一个节点,一个保存next。
每次遍历将current的next修改为prev，然后向前移动prev，current 指针。return prev 


```
func reverseList(head *ListNode) *ListNode {
   	var prev *ListNode
	var next *ListNode
	curr := head

	for curr != nil{
		next = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}
```
