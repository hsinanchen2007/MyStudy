**F1:哈希实现**
```
func removeDuplicateNodes(head *ListNode) *ListNode {
	if head == nil || head.Next == nil{
		return head
	}
	var m = make(map[int]bool)
	m[head.Val] = true
	var leftNode,rightNode = head,head.Next
	for rightNode != nil{
		if _,ok := m[rightNode.Val];ok{
			leftNode.Next = rightNode.Next
			rightNode = leftNode.Next
		}else{
			m[rightNode.Val] = true
			leftNode = leftNode.Next
			rightNode = rightNode.Next
		}
	}
	return head
}
```
**F2:for+for**
```
func removeDuplicateNodes(head *ListNode) *ListNode {
	if head == nil || head.Next == nil{
		return head
	}
	var curNode,leftNode,rightNode = head,head,head.Next
	for curNode != nil{
		leftNode,rightNode = curNode,curNode.Next
		for rightNode !=nil{
			if rightNode.Val == curNode.Val{
				leftNode.Next = rightNode.Next
				rightNode = leftNode.Next
			}else{
				leftNode = leftNode.Next
				rightNode = rightNode.Next
			}
		}
        curNode = curNode.Next
	}
	return head
}
```

