### 解题思路
使用三个指针，就可以解决这个问题
> [更多](https://github.com/googege/GOFamily)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapPairs(head *ListNode) *ListNode {
    prev := new(ListNode)
    prev.Next = head
    t := prev
    for prev.Next != nil && prev.Next.Next != nil {
        cur := prev.Next
        ne  := cur.Next
        prev.Next,ne.Next,cur.Next = ne,cur,ne.Next
        prev = cur
    }
    return t.Next
}
```