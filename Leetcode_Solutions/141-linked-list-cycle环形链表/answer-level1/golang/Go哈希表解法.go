### 解题思路
用一个映射存储经过的节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
    if head==nil{
        return false
    }
    p:=head
    m:=make(map[*ListNode]bool)
    for{
        if p.Next==nil{
            return false
        }
        if m[p]==true{
            return true
        }
        m[p]=true
        p=p.Next
    }
}
```