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
    def swapPairs(self, head: ListNode) -> ListNode:
        k = head
        n = []
        while(k != None):
            n.append(k)
            k = k.next
        
        if len(n) == 0:
            return None
        if len(n) == 1:
            return n[0]
        if len(n) == 2:
            n[1].next = n[0]
            n[0].next = None
            return n[1]

        for l in range(0,len(n),2):
            if l != 0 and l + 2 < len(n):
                (n[l+1]).next = n[l]
                (n[l]).next = n[l+2]
                (n[l-1]).next = n[l+1]
                tep = n[l+1]
                n[l+1] = n[l]
                n[l] = tep
            if l == 0:
                (n[1]).next = n[0]
                (n[0]).next = n[2]
                tep = n[l+1]
                n[l+1] = n[l]
                n[l] = tep
            if l + 2 == len(n):
                (n[l+1]).next = n[l]
                (n[l-1]).next = n[l+1]
                n[l].next = None
                tep = n[l+1]
                n[l+1] = n[l]
                n[l] = tep
        r = n[0]
        return r
```