### 解题思路
leetcode206. 反转链表

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseList(head *ListNode) *ListNode {
   var res []int
   tmp:=reverse(nil, head)
   for tmp!=nil {
     res = append(res, tmp.Val)
     tmp = tmp.Next  
   }
   return reverse(nil, head)
}

func reverse(pre, cur *ListNode) *ListNode {
   if cur == nil {
      return pre
   }
   head := reverse(cur, cur.Next)
   cur.Next = pre
   return head
}
```