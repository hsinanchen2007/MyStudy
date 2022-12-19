思路是遍历链表，将遍历值放入列表中，对列表进行升序排序，按顺序填充链表即可
```python
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