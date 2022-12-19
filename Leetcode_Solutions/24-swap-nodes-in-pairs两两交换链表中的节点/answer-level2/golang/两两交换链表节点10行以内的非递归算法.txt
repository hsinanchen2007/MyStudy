// 加上一个空的头节点Next指针指向Head指针
// 然后对满足节点的指针pre节点的Next和Next.Next都不为空的指针进行操作
// 这样避免了单指针节点为奇数的时候单独处理

func swapPairsTwoSimple(head *ListNode) *ListNode {
	pre := new(ListNode)
	pre.Next = head
	new_head := pre
	for pre.Next != nil && pre.Next.Next != nil {
		a := pre.Next
		b := pre.Next.Next
		pre.Next, b.Next, a.Next = b, a, b.Next
		pre = a
	}
	return new_head.Next
}

附上更多解法 https://github.com/liuyanan66/LeetCodeCode/blob/master/LeetCode/lc_24.swap_pairs.go