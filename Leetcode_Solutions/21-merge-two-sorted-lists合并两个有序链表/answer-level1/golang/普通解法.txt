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
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
    pre := &ListNode{
        Val: 0,
        Next: nil,
    }
    cur := pre
    for nil != l1 || nil != l2 {
        if nil != l1 && nil != l2 {
            if l1.Val < l2.Val {
                newNode := &ListNode{
                    Val: l1.Val,
                    Next: nil,
                }
                cur.Next = newNode
                l1 = l1.Next
            } else {
                newNode := &ListNode{
                    Val: l2.Val,
                    Next: nil,
                }
                cur.Next = newNode
                l2 = l2.Next
            }
        } else if nil == l1 {
            newNode := &ListNode{
                Val: l2.Val,
                Next: nil,
            }
            cur.Next = newNode
            l2 = l2.Next
        } else if nil == l2 {
            newNode := &ListNode{
                Val: l1.Val,
                Next: nil,
            }
            cur.Next = newNode
            l1 = l1.Next
        }

        cur = cur.Next
    }
    return pre.Next
}
```