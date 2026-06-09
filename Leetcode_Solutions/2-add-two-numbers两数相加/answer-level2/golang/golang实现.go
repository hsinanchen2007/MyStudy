
```golang []
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    var ret = &ListNode{0, nil}
	var p = ret
	var carry = 0
	for l1 != nil || l2 != nil || carry != 0 {
		var a1, a2 int
		if l1 != nil {
			a1 = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			a2 = l2.Val
			l2 = l2.Next
		}
		sum := a1 + a2 +carry
		carry = sum / 10
		p.Next = &ListNode{sum%10,nil}
		p = p.Next
	}
	return ret.Next
}
```