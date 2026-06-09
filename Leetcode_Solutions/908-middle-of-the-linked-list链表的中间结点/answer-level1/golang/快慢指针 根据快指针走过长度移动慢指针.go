```
//ListNode Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	var cur *ListNode = head
	var count = 1
	var result *ListNode = head
	var middle = 1
	for nil != cur.Next {
		cur = cur.Next
		count++
		if count+1 > middle*2 {
			result = result.Next
			middle++
		}
	}
	return result
}
```
demo [1, 2, 3, 4, 5, 6]
当cur从4遍历到5，count=5，未执行count+1 > middle*2，middle=3；执行count+1 > middle*2后，middle不变middle=3
当cur从5遍历到6，count=6，未执行count+1 > middle*2，middle=3；执行count+1 > middle*2后，middle加一middle=4
看了评论区，fast=fast.Next.Next快指针走两步，slow=slow.Next慢指针走一步，比较好理解，count+1 > middle*2这个条件一开始自己也比较模糊，试出来的
