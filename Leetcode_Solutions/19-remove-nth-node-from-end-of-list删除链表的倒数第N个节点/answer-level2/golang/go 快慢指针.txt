### 解题思路
设置快慢指针，快指针先执行n步，然后一起执行，当快指针到达指针尾部。慢指针刚好处在倒数n+1的位置。
再处理下特殊情况，删除的元素刚好是头元素的情况

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
     fast,slow:=head,head

     for i:=0;i<n;i++ {
          if fast.Next == nil {
            return head.Next
        }
        fast = fast.Next
       
     }

     for {
         if fast.Next==nil {
            slow.Next = slow.Next.Next
            break
         }else {
             fast = fast.Next
             slow = slow.Next
         }
     }
    return head
}
```