### 解题思路
使用go自带的list1实现栈结构！

### 代码

```golang
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	stack1 := list.New()
	stack2 := list.New()
	// 入栈
	for l1!= nil {
		stack1.PushFront(l1.Val)
		l1 = l1.Next
	}

	for l2!= nil {
		stack2.PushFront(l2.Val)
		l2 = l2.Next
	}



	p := l1
	carry := 0
	for stack1.Len() > 0 && stack2.Len() > 0 {
		val := stack1.Front().Value.(int) + stack2.Front().Value.(int) + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}

		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node

		stack1.Remove(stack1.Front())
		stack2.Remove(stack2.Front())
	}

	for stack1.Len() > 0{
		val := stack1.Front().Value.(int) + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}

		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node
		stack1.Remove(stack1.Front())
	}
	for stack2.Len() > 0{
		val := stack2.Front().Value.(int) + carry
		carry = 0
		if val > 9 {
			val -= 10
			carry = 1
		}

		node := &ListNode{
			Val:  val,
			Next: p,
		}
		p = node
		stack2.Remove(stack2.Front())
	}

	if carry > 0 {
		node := &ListNode{
			Val:  carry,
			Next: p,
		}
		p = node
	}

	return p
}

```