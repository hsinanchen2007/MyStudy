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
    sum := (l1.Val + l2.Val) % 10
    carry := (l1.Val + l2.Val) / 10
    head := &ListNode{Val: sum, Next: nil}
    newNode := head

    for l1.Next != nil && l2.Next != nil {
        l1 = l1.Next
        l2 = l2.Next
        sum = (l1.Val + l2.Val + carry) % 10
        carry = (l1.Val + l2.Val + carry) / 10
        newNode.Next = &ListNode{Val: sum, Next: nil}
        newNode = newNode.Next
    }
    for l1.Next != nil {
        l1 = l1.Next
        sum = (l1.Val + carry) % 10
        carry = (l1.Val + carry) / 10
        newNode.Next = &ListNode{Val: sum, Next: nil}
        newNode = newNode.Next
    }
    for l2.Next != nil {
        l2 = l2.Next
        sum = (l2.Val + carry) % 10
        carry = (l2.Val + carry) / 10
        newNode.Next = &ListNode{Val: sum, Next: nil}
        newNode = newNode.Next
    }
    if carry == 1 {
        newNode.Next = &ListNode{Val: 1, Next: nil}
        newNode = newNode.Next
    }
    return head
}
```

![image.png](https://pic.leetcode-cn.com/956b45fa717d16b698ccf6a0385af8764466907fee5a7db49b60be9c9e80c0e2-image.png)
