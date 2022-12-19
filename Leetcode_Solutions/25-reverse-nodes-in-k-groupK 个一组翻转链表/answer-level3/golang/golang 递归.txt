```
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
    if head == nil {
                 return nil
          }
  
          index := 0
          p, cur := head, head
          var pre, temp *ListNode
          pre = nil
          temp = nil
  
          for p != nil && index < k {
  
                  p = p.Next
                  index++
          }
          
          if index < k {
                  return head
          } else {
                  loop := 0
                  for loop < k {
                          temp = cur.Next
                          cur.Next = pre
                          pre = cur
                          cur = temp
                          loop++
                  }       
                  head.Next = reverseKGroup(temp, k)
                  return pre
          }       

}
```
