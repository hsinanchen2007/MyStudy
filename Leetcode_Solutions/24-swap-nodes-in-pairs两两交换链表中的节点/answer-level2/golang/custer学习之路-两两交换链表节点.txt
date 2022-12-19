- 返回值：交换完成的子链表
- 调用单元：设需要交换的两个点为 head 和 next，head 连接后面交换完成的子链表，next 连接 head，完成交换
- 终止条件：head 为空指针或者 next 为空指针，也就是当前无节点或者只有一个节点，无法进行交换

> 和链表反转类似，关键在于，有三个指针，分别指向前后和当前节点。
> 不同点是两两交换后，移动节点步长为2。

```go
// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	newHead := head.Next
	newHead.Next, head.Next = head, swapPairs(newHead.Next)
	return newHead
}
```

方便自己理解，可以写成下面这样：

```go
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    first := head // 需要交换的第一个节点
    second := head.Next // 需要交换的第二个节点
    third := head.Next.Next // 下一组需要交换的第一个节点
    
    second.Next = first // 把第二个节点的后继指针Next指向第一个节点
    first.Next = swapPairs(third) // 把第一个节点的后继指针Next指向下一组完成交换之后的第一个节点
    
    return second 
}
```