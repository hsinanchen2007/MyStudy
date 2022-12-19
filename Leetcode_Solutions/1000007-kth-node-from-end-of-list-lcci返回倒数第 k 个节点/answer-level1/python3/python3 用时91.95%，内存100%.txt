### 解题思路
整个算法只需要遍历一次单链表。需要两个辅助指针p,q。初始情况下p,q 都位于head处，先让p走k-1步，然后p,q 同时向前走，直到p走到链表的末尾，此时q指向即为所求。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        p = head
        while(k-1):
            p = p.next
            k -= 1
        q = head
        while (p.next != None):
            p = p.next
            q = q.next
        return q.val

    
```