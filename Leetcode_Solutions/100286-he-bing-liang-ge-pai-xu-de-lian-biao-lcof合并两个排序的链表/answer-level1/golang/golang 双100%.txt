### 解题思路
递归

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
    if l1 == nil {
        return l2
    }else if l2 == nil {
        return l1
    }
    if l1.Val<l2.Val {
        l1.Next = mergeTwoLists(l1.Next,l2)
        return l1
    }else{
        l2.Next = mergeTwoLists(l2.Next,l1)
        return l2
    }
}
```