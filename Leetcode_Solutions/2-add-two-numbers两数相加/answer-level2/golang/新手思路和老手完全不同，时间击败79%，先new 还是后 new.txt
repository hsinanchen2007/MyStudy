### 解题思路
此处撰写解题思路
1. 一种思路是，只要还有值要写入，再new 一个node 来写入该值，避免最后一个节点的处理
2. 另外一种思路是，每次写完当前值，都准备好写一个节点，这样需要记住前一个节点，处理最后一个节点

`刚开始采用的是第一种方式，最后返回的是header.Next, 写着写着觉得这样header 节点是不是就不会被回收了？ 于是采用了第二种方式，
回头想想，这点空间内存无所谓的，应该才有更优雅简洁的编码方式`

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    header := new(ListNode)
	// 当前待写入节点
	curNode := header
	// 最后一个有效节点
	lastNode := curNode
	// 进位值
	moreInt := 0
	// 当前值
	curInt := 0
	for nil != l1 && nil != l2 {
		curInt = (l1.Val + l2.Val + moreInt) % 10
		moreInt = (l1.Val + l2.Val + moreInt) / 10
		// 计算得到当前节点
		curNode.Val = curInt
		// 准备下一个节点
		tmp := new(ListNode)
		curNode.Next = tmp
		// 记住当前节点位置
		lastNode = curNode
		// 游标下移
		curNode = curNode.Next
		l1 = l1.Next
		l2 = l2.Next
	}

	for nil != l1 {
		curInt = (l1.Val + moreInt) % 10
		moreInt = (l1.Val + moreInt) / 10
		curNode.Val = curInt
		tmp := new(ListNode)
		curNode.Next = tmp
		lastNode = curNode
		// 游标下移
		curNode = curNode.Next
		l1 = l1.Next
	}
	for nil != l2 {
		curInt = (l2.Val + moreInt) % 10
		moreInt = (l2.Val + moreInt) / 10
		curNode.Val = curInt
		tmp := new(ListNode)
		curNode.Next = tmp
		lastNode = curNode
		// 游标下移
		curNode = curNode.Next
		l2 = l2.Next
	}
	// 表示最后还有进位
	if moreInt > 0 {
		curNode.Val = moreInt
		curNode.Next = nil
		lastNode = curNode
	}

	lastNode.Next = nil
	return header
}
```