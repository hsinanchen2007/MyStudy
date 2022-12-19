### 解题思路
遍历列表，记录第n个，然后将重新赋值

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        count = 0
        first = head

        while first:
            count += 1
            first = first.next
        
        idx = count - n
        first = dummy
        while idx > 0:
            idx -= 1
            first = first.next
        first.next = first.next.next
        return dummy.next

```