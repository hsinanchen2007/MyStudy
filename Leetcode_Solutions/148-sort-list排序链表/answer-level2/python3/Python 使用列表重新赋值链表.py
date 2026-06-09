### 解题思路
将列表的值排序，然后依次重新赋值给链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        ptr = head
        p_queue =[]
        while ptr != None:
            p_queue.append(ptr.val)
            ptr = ptr.next
        ptr = head
        for item in sorted(p_queue):
            ptr.val = item
            ptr = ptr.next
        return head

```