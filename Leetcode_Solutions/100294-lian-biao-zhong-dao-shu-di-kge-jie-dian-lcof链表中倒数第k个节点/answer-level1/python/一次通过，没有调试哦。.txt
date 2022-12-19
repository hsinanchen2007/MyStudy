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
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slowPtr = head
        fastPtr = head
        for i in range(k):
            fastPtr = fastPtr.next
        while fastPtr != None:
            fastPtr = fastPtr.next
            slowPtr = slowPtr.next
        return slowPtr

```