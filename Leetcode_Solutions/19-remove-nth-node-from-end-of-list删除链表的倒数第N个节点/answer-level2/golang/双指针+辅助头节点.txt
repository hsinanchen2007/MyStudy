### 解题思路
一个循环中，每次操作两个指针（强行算作是一次遍历 以符合题目要求，当感觉效率上并没有提升

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
    count := 0
    node := head
    fakeHead := &ListNode {
        Val: 0,
        Next: head,
    }
    deletingNode := fakeHead
    for node != nil {
        if count < n {
            count++
        } else {
            deletingNode = deletingNode.Next
        }
        node = node.Next
    }
    deletingNode.Next = deletingNode.Next.Next
    return fakeHead.Next
}
```