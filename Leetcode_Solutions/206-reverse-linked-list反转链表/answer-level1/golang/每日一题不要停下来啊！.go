### 解题思路
这个题已经用Java做过了，就用Go再实现一遍

### 代码

```go
func reverseList(head *ListNode) *ListNode {
    var last *ListNode
    cur := head
    for true {
        if cur == nil {
            break;
        }
        next := cur.Next
        cur.Next = last
        last = cur
        cur = next
    }
    return last;
}
```