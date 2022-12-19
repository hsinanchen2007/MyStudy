### 解题思路
利用堆来解决
时间复杂度:$O(NlogK)$
空间复杂度:$O(K)$

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        dummyNode = ListNode(0)
        heap = []
        cur = dummyNode
        # Time complexity : O(nlogk)
        # Space complexity: O(k)       
        for i in range(len(lists)):
            if lists[i]:
                heapq.heappush(heap, (lists[i].val, i))
                lists[i]= lists[i].next
        while heap:
            val, index = heapq.heappop(heap)
            cur.next = ListNode(val)
            cur = cur.next
            if lists[index]:
                heapq.heappush(heap, (lists[index].val, index))
                lists[index] = lists[index].next
        return dummyNode.next
```