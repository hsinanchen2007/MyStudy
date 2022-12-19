```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
    
    // 初始化切片
    stack := []int{}
    
    // 把ListNode的值顺序放入到切片中
    for head != nil {
        stack = append(stack, head.Val)
        head = head.Next
    }
    
    // 创建一个新头
    newHead := &ListNode{}
    // 当前节点
    currListNode := newHead
    // 从后往前遍历切片，链表头结点是空节点，第二个节点开始才是真正的值
    for i := len(stack) - 1; i >= 0; i-- {
        currListNode.Next = &ListNode{Val: stack[i], Next: nil}
        currListNode = currListNode.Next
    }
    
    // 去掉头结点
    return newHead.Next
}
```
