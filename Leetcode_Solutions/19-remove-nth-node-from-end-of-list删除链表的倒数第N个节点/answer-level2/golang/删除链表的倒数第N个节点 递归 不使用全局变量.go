**最好的说明就是代码吧**
```
type ListNode struct {
     Val  int
     Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
     if head == nil || n < 0{
          return head
     }
     headNth := _removeNthFromEnd(head, n)
     newHead := head
     // 如果倒数第N个是头节点，则删除头节点返回新的头
     if headNth == n {
          newHead = head.Next
          head.Next = nil
     }
     return newHead
}

// 真正的递归函数，得到节点是倒数第几个元素
func _removeNthFromEnd(node *ListNode, n int) int{
     if node.Next == nil { // 如果是最后一个元素，则表示这个节点为倒数第一个
          return 1
     }
     endNth := _removeNthFromEnd(node.Next, n) + 1 // 得到自己是倒数第几个
     if endNth == n+1 { // 如果是倒数第N+1个（也就是第N个父节点）
          node.Next = node.Next.Next // 删除倒数第N个(注意node.next是肯定存在的，因为此时node肯定不是最后一个节点)
     }
     return endNth
}
```
