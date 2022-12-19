
![图片.png](https://pic.leetcode-cn.com/fead06ad3169d3832d46e3dbcb843f6da797d2912441c5173e54ad2e07eb2911-%E5%9B%BE%E7%89%87.png)


```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	p := l1
	q := l2
	currentHead := head
	var sum,carry int
	for true  {
		if q != nil || p != nil {
			var x,y int
			if p!=nil {
				x=p.Val
				p = p.Next
			}
			if q!=nil {
				y =q.Val
				q = q.Next
			}

			sum = carry + x + y
			carry = sum / 10
		} else {
			break
		}
		currentHead.Val = sum % 10
		if p!=nil||q!=nil {
			currentHead.Next = &ListNode{}
			currentHead = currentHead.Next
		}

	}
	if carry != 0 {
		currentHead.Next = &ListNode{carry, nil}
	}
	return head
}
```
