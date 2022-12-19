这个题的难点其实是处理头节点的情况，头节点由于没有父节点所以会产生很多特殊情况，所以我们我们可以自己定义一个节点指向头节点，这样头节点就变成了普通节点，逻辑会非常清晰
```
func swapPairs(head *ListNode) *ListNode {
	headhead := &ListNode{Next:head} // 定义一个指向头节点的节点
	p1, p2 := headhead, head // 注意p1代表第一个节点的父节点而非第一个节点，p2代表第2个节点的父节点


	for p2 != nil && p2.Next != nil { // p2== nil表示没有节点了,p2.next=nil表示只有一个节点了
		// 之前p1->p2->p3->...变化后p1->p3->p2->...
		p1.Next = p2.Next // p1->p3
		p2.Next = p2.Next.Next // p2->...
		p1.Next.Next = p2 // p1->p3->p2


		p1 = p2 // p1向前移动到p2
		p2 = p1.Next // p2移动到p1前面
	}
	return headhead.Next 
}
```
