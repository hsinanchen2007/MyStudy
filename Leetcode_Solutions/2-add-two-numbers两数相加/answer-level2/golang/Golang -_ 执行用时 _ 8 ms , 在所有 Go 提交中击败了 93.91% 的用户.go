### 解题思路
1. 同时对l1、l2 loop一遍，对单个数字进行加法和进位
2. 最后做边界处理返回结果

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
    if l1 == nil {
        return l2
    }
    if l2 == nil {
        return l1
    }

    dummy := &ListNode{0, nil}
    sum := (l1.Val+l2.Val) % 10
    carry := (l1.Val+l2.Val) / 10
    current := &ListNode{sum, nil}
    l1 = l1.Next
    l2 = l2.Next
    dummy.Next = current
    for l1 != nil && l2 != nil {
        sum = (l1.Val + l2.Val + carry) % 10
        carry = (l1.Val + l2.Val + carry) / 10
        current.Next = &ListNode{sum, nil}
        current = current.Next
        l1 = l1.Next
        l2 = l2.Next
    }
    for l2 != nil {
        sum = (carry + l2.Val) % 10
        carry = (carry + l2.Val) / 10
        current.Next = &ListNode{sum, nil}
        l2 = l2.Next
        current = current.Next
    }
    for l1 != nil {
        sum = (carry + l1.Val) % 10
        carry = (carry + l1.Val) / 10
        current.Next = &ListNode{sum, nil}
        l1 = l1.Next
        current = current.Next
    }
    if carry != 0 {
        current.Next = &ListNode{carry, nil}
    }
    
    return dummy.Next
}
```
### 复杂度分析
时间复杂度：O(max(m, n)) m为l1长度，n为l2长度
空间复杂度：O(max(m, n)) m为l1长度，n为l2长度