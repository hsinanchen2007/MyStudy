思路 就是遍历两个链表，判断两值相加，注意进位就可以了。
```
    firstNode := &ListNode{0, nil}
        cNode := firstNode
	curL1 := l1
	curL2 := l2
	var v1, v2 int
	for {
		if curL1 != nil {
			v1 = curL1.Val
			curL1 = curL1.Next
		} else {
			v1 = 0
		}
		if curL2 != nil {
			v2 = curL2.Val
			curL2 = curL2.Next
		} else {
			v2 = 0
		}

		sum := v1 + v2 + cNode.Val
		cNode.Val = sum -10
		next :=sum/10
		if curL1 == nil && curL2 == nil&&next==0 {
			return firstNode
		}
		cNode.Next = &ListNode{next, nil}
		cNode = cNode.Next
	}
```
	
