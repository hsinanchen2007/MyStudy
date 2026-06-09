### 解题思路
快指针先走n步，然后快慢指针一起走，快指针走到头，慢指针是第n个待删除点

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fast,slow=head,head
        while n:
            fast=fast.next
            n-=1
        pre=ListNode(-1)
        dummy=pre
        pre.next=head
        while fast:
            pre=slow
            slow,fast=slow.next,fast.next
        if slow:
            pre.next=slow.next
        return dummy.next
```