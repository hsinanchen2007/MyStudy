### 解题思路

空间复杂度$O(1)$

### 代码

```python []
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        p = q = head
        for _ in range(k):
            q = q.next
        while q:
            p = p.next
            q = q.next
        return p
```