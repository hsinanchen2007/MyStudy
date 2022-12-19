### 解题思路
创建两个链表分别记录比x大和比x小的节点，合并的时候记得第二个链表末尾置空，否则出现环

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        dm1=p1=ListNode(-1)
        dm2=p2=ListNode(-1)
        while head:
            if head.val<x:
                p1.next=head
                p1=p1.next
            else:
                p2.next=head
                p2=p2.next
            head=head.next
        p1.next=dm2.next
        p2.next=None
        return dm1.next
```

