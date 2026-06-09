```
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}
	lenA := 0
	lenB := 0
	countA := headA
	for {
		lenA++
		if countA.Next == nil {
			break
		}
		countA = countA.Next
	}

	countB := headB
	for {
		lenB++
		if countB.Next == nil {
			break
		}
		countB = countB.Next
	}
	if lenA > lenB {
		for i := 0; i < lenA-lenB; i++ {
			headA = headA.Next
		}
	} else {
		for i := 0; i < lenB-lenA; i++ {
			headB = headB.Next
		}
	}
	for {
		if headA == headB {
			return headA
		}
		if headA.Next == nil || headB.Next == nil {
			return nil
		}
		headA = headA.Next
		headB = headB.Next
	}
}
```
