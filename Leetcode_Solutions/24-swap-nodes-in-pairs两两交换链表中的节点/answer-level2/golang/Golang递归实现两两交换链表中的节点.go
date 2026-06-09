解题思路：
1.找到终止递归的条件：当链表只剩下一个节点或者没有节点的时候，递归终止。

2.寻找返回值：希望得到已经处理好的链表，即是交换给上一级递归的节点已经完成交换处理。

3.本层递归应该做什么：三个节点：head、head.Next、完成交换的部分链表。本层递归完成前两个节点的交换即可。
```
func swapPairs(head *ListNode) *ListNode {
    if head == nil ||head.Next == nil {
        return head
    }
    next := head.Next
    head.Next = swapPairs(next.Next)
    next.Next = head
    return next
}
```
