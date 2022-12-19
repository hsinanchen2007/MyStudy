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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    if l1 == nil && l2 ==nil {
        return nil
    }
    if l1 == nil {
        return l2
    }
    if l2 == nil{
        return l1
    }
    //当前节点
    local := &ListNode{
        Val:l1.Val + l2.Val,
    }
    if local.Val >= 10 {
        // 创建溢出节点与l1 合并
        next := &ListNode{
            Val: 1,
        }
        local.Val -= 10
        l1.Next = addTwoNumbers(l1.Next,next)
    }
    local.Next = addTwoNumbers(l1.Next,l2.Next)
    return local
}
```