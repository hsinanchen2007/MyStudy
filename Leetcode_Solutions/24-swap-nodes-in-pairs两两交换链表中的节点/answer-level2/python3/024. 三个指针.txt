### 解题思路
三个指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummynode = ListNode(0)
        pre = dummynode
        pre.next = head

        while pre.next and pre.next.next:
            cur = pre.next
            future = pre.next.next

            cur.next = future.next
            future.next = cur
            pre.next = future
            pre = cur
        
        return dummynode.next


        
```