### 解题思路
・listsにある全てのノードをヒープに保存する
・ヒープを一つずつpopし、新しい連結リストを作成
・作った連結リストの最初のノードを戻す

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        cal = ListNode(0)
        res = cal
        heap = []
        for node in lists:
            while node:
                heapq.heappush(heap, node.val)
                node = node.next
        while heap:
            cal.next = ListNode(heapq.heappop(heap))
            cal = cal.next
        return res.next
```