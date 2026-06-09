### 解题思路
此处撰写解题思路

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
    pointer1 := head
    pointer2 := head
    for pointer2.Next != nil && pointer2.Next.Next != nil{
        pointer1 = pointer1.Next
        pointer2 = pointer2.Next.Next
    }
    if pointer2.Next != nil{
        pointer1 = pointer1.Next
    }
    return pointer1
}
```