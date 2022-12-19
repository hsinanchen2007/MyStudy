### 解题思路
数据丢失，模拟带进位加法

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