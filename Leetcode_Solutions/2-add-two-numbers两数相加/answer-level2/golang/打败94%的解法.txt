完整代码
```
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var sumListNode  *ListNode  	// 求和链表
	var currentListNode *ListNode	// 求和链表当前节点
	currentListNode1 := l1 			// 复制参数指针，避免遍历时候影响输入参数
	currentListNode2 := l2			// 复制参数指针，避免遍历时候影响输入参数
	var isCarry int					// 是否进位
	var int1 int					// 记录链表1 当前节点Val值
	var int2 int					// 记录链表2 当前节点Val值
	var sum int						// int1 + int2 + isCarry
	for currentListNode1 != nil || currentListNode2 != nil || isCarry != 0 /*当前有进位*/{
		int1 = 0
		int2 = 0
		sum  = 0
		if currentListNode1 != nil {
			int1 = currentListNode1.Val
			currentListNode1 = currentListNode1.Next
		}
		if currentListNode2 != nil {
			int2 = currentListNode2.Val
			currentListNode2 = currentListNode2.Next
		}
		sum =  int1 + int2 + isCarry
		isCarry = 0
		if sum >= 10 { // 需要进位
			sum = sum - 10
			isCarry = 1
		}

		if sumListNode == nil {
			sumListNode = &ListNode{
				Val: sum,
			}
			currentListNode = sumListNode
			continue
		}
		currentListNode.Next = &ListNode{
			Val: sum,
		}
		currentListNode = currentListNode.Next
	}
	return sumListNode
}
```

执行结果
![image.png](https://pic.leetcode-cn.com/b59afdf9105b1a90070b8f494e8a267735d35a36466f5e1d3f82f1b2d1bd1ebd-image.png)
