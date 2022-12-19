### 解题思路
对于原来的head而言，我们从前往后依次获取元素。对于新的head而言，我们依次将新的元素添加到头部并更新头部的信息

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        
        new_head = None
        while head:
            next_head = head.next
            head.next = new_head
            new_head = head
            head = next_head
        return new_head
```