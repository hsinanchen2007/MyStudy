### 解题思路
*链表个数为奇数，返回中间节点；链表个数为偶数，返回中间两个结点左面的节点*
选用快慢指针的做法，快慢指针都指向头结点，利用一个循环来进行移动快慢指针，快指针每次移动两步，慢指针每次移动一步，当快指针为空，或快指针的下一个结点为空，循环结束，此时慢指针所指的节点即为中间节点

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
   fast := head
   slow := head
   for fast != nil && fast.Next != nil {
       fast = fast.Next.Next
       slow = slow.Next
   }
   return slow
    
}
```