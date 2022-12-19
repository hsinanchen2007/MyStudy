思路是遍历链表，放入优先队列，按顺序弹出即可
```python
from queue import PriorityQueue
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        ptr = head
        p_queue = PriorityQueue()
        while ptr != None:
            p_queue.put(ptr.val)
            ptr = ptr.next
        ptr = head
        while not p_queue.empty():
            ptr.val = p_queue.get()
            ptr = ptr.next
        return head
```