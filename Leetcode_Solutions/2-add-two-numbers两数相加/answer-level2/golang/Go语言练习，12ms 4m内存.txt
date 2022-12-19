```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1 == nil {
		return l2
	}

	if l2 == nil {
		return l1
	}

	var ret *ListNode = l1
	var l1_prev *ListNode = nil
	var isUp bool = false

	for true {
		if !isUp && l2 == nil && l1.Next == nil {
			break
		}

		if isUp {
            l1.Val += 1
            if l1.Val >= 10 {
                l1.Val = 0
            } else {
                isUp = false
            }
		}

		if l2 != nil {
			var sum = l1.Val + l2.Val
			l2 = l2.Next
			if sum >= 10 {
				sum -= 10
				isUp = true
			}
			l1.Val = sum
		}

		if l1.Next == nil {
			l1.Next = &ListNode{0, nil}
		}
		l1_prev = l1
		l1 = l1.Next
	}

	if l1.Val == 0 {
		l1_prev.Next = nil
	}
	return ret
}
```
