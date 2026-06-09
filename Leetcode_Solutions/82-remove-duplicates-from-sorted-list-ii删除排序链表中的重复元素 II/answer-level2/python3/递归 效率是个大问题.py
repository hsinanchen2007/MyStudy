### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or head.next == None:
            return head
        slow,fast = head,head.next
        while fast and fast.val == slow.val:
            fast = fast.next
        if fast == slow.next:
            head.next= self.deleteDuplicates(head.next)
            return head
        else:
            return self.deleteDuplicates(fast)


```