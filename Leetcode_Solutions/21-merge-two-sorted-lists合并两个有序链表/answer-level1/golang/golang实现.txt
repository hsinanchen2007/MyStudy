此题目思路倒是很简单，每次比较两个链表第一个元素，取最小的那个赋值到新链表。难的是链表的操作以及golang的语法实现不太熟悉，想的出来写不出来。
```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	resListNode:=new(ListNode)//resListNode.next指向两个链表中第一个最小的元素
	if l1==nil {
		return l2
	}
	if l2==nil {
		return l1
	}
	**tmpListNode:=resListNode//他们保存了相同的地址，tmpListNode用于后续迭代，向后遍历**
	for{
		if l1!=nil && l2!=nil {
			if l1.Val < l2.Val {
				tmpListNode.Next=l1
				**l1=l1.Next**
			}else {
				tmpListNode.Next=l2
				**l2=l2.Next**
			}
			**tmpListNode=tmpListNode.Next**
		}
		if l1==nil &&l2!=nil {
			tmpListNode.Next=l2
			break
		}
		if l1!=nil && l2==nil{
			tmpListNode.Next=l1
			break
		}
	}
	return resListNode.Next// resListNode.Next代表tmplistnode第一次取得较小值，是通过地址的引用实现的
}

```
