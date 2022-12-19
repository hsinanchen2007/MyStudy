### 解题思路
两数相加

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
  dummy := new(ListNode) // 定义虚拟头节点
  p := dummy // 定义游标
  carry := 0 // 进位变量
  for l1 != nil || l2 != nil || carry !=0 {
    sum := carry // sum初始化为carry，首先计算进位
    if l1 != nil {
      sum += l1.Val
      l1 = l1.Next
    }
    if l2 != nil {
      sum += l2.Val
      l2 = l2.Next
    }
    // 以sum对10取模的结果来创建新的节点
    p.Next = &ListNode{ Val:sum%10 }
    p = p.Next // p向后移动一个节点，指向新创建的当前节点
    carry = sum /10// 更新进位
  }
  return dummy.Next
}
```

进阶

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
  dummy := new(ListNode) // 定义虚拟头节点
  p := dummy // 定义游标
  var stack []int
  for l1 != nil || l2 != nil {
    sum := 0 // sum初始化为carry，首先计算进位
    if l1 != nil {
      sum += l1.Val
      l1 = l1.Next
    }
    if l2 != nil {
      sum += l2.Val
      l2 = l2.Next
    }
    stack = append(stack, sum)
  }
  fmt.Println("stack: ", stack)
  carry := 0
  var stack2 []int
  for len(stack)>0 {
    s := stack[len(stack)-1]
    stack =stack[:len(stack)-1]
    sum := carry
    sum += s%10
    carry = s/10
    stack2 = append(stack2, sum)
  }
  fmt.Println("stack2: ",stack2)
  for len(stack2)>0 {
    s := stack2[len(stack2)-1]
    stack2 =stack2[:len(stack2)-1]
    p.Next = &ListNode{Val:s}
    p = p.Next
  }
  return dummy.Next
}
```