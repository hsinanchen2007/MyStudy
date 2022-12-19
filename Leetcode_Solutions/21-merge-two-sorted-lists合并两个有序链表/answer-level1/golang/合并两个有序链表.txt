### 21.合并两个有序链表
题意：将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

解题思路：傻瓜题,考察链表基本操作

1A 4ms 2.6M
```
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := new(ListNode)
	result := head
	for {
		if l1 == nil && l2 == nil{
			break
		}
		if l1 == nil{
			head.Next = l2
			break
		}
		if l2 == nil{
			head.Next = l1
			break
		}
		if l1.Val <= l2.Val{
			temp := new(ListNode)
			temp.Val = l1.Val
			head.Next = temp
			head = temp
			l1 = l1.Next
		}else{
			temp := new(ListNode)
			temp.Val = l2.Val
			head.Next = temp
			head = temp
			l2 = l2.Next
		}
	}
	return result.Next
}
```