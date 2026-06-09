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
    def middleNode(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        if head.next is None:
            return head
        count = 0
        temp = head
        while temp:
            count = count + 1
            temp = temp.next
        low = 0
        high = count
        mid = low + (high-low)//2 
        while head:
            head = head.next 
            mid = mid - 1
            if mid == 0:
                break
        return head 
```