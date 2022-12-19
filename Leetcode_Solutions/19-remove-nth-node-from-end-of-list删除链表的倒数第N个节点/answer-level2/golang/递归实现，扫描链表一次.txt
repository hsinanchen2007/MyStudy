 总体思路是每次进入递归调用的时候传入层级layer（标记当前是链表的第几个元素）。如果输入的节点是nil，return链表的元素总个数maxNum(layer-1)。在每一层比较layer和maxNum的关系，如果layer = maxNum-n+1说明是要删除的元素，那么把这个元素的Next元素返回给上一层，如果layer = maxNum-n说明是要删除的元素的前置元素，把这个元素的Next指向下一层递归返回的元素即可。
下面是golang的实现  
```
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    head, _ = handler(head, 1, n)
	return head
}

func handler(head *ListNode, layer, n int) (*ListNode, int) {
	if head == nil {
		return head, layer - 1
	}
	next, maxNum := handler(head.Next, layer+1, n)
	if layer == maxNum-n + 1 {
		return head.Next, maxNum
	} else if layer == maxNum-n {
		head.Next = next
		return head, maxNum
	} else {
		return head, maxNum
	}
}
```