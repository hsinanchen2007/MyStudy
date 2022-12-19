```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	pre := new(ListNode)
	pre.Val = 0
	cur := pre
	carry := 0
	for l1 != nil || l2 != nil {
		var (
			x = 0
			y = 0
		)
		if l1 != nil {
			x = l1.Val
		}

		if l2 != nil {
			y = l2.Val
		}

		sum := x + y + carry
		
		carry =sum / 10
		sum = sum % 10

		newNode := new(ListNode)
		newNode.Val = sum
		cur.Next = newNode
		cur = cur.Next

		if l1 != nil {
			l1 = l1.Next
		}

		if l2 != nil {
			l2 = l2.Next
		}
	}
    
    // 最高位是进位得来的
    // 那么就直接新建一个节点
	if carry == 1 {
		newNode := new(ListNode)
		newNode.Val = carry
		cur.Next = newNode
	}
	// 因为第一位是0 所以需要放弃
	return pre.Next
}
```

非常简单的题目，因为是逆序的反而更简单，就按照平常算加法的方式从低位往高位去计算，当数字大于9 时就进以为，在下一位计算的时候加上这个进位
