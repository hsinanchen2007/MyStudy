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
    pre := &ListNode{
        Val:0,
        Next:nil,
    }
    cur := pre

    carry := 0

    for nil != l1 || nil != l2 {
        x, y := 0, 0
        if nil != l1 {
            x = l1.Val
            l1 = l1.Next
        }
        if nil != l2 {
            y = l2.Val
            l2 = l2.Next
        }

        sum := x + y + carry

        // 计算进位
        carry = sum / 10
        // 计算当前位数字
        sum = sum % 10
        newNode := &ListNode{
            Val: sum,
            Next:nil,
        }
        cur.Next = newNode
        cur = cur.Next
    }
    if carry == 1 {
        newNode := &ListNode{
            Val: 1,
            Next:nil,
        }
        cur.Next = newNode
    }
    return pre.Next
}
```