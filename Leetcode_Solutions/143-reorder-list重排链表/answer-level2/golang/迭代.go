### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reorderList(head *ListNode)  {
    if nil == head || nil == head.Next {
        return
    }
    var v [100000]*ListNode
    p := head; i := 1
    for nil != p {
        v[i] = p
        p = p.Next
        i++
    }
    i--
    j := 1
    for j < i && i != j+1 {
        v[j].Next = v[i]
        v[i].Next = v[j+1]
        v[i-1].Next = nil
        j += 1
        i--
    }
}
```