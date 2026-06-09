### 解题思路
头绕晕了，还是用堆吧。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode: 
        if not head: return head

        heap = []
        heapq.heapify(heap)

        while head:
            heapq.heappush(heap, head.val)
            head = head.next

        root = ListNode(0)
        cur = root
        while heap:
            val = heapq.heappop(heap)
            cur.next = ListNode(val)
            cur = cur.next

        return root.next
```