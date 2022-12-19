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
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        m = []
        k = head
        if k.next == None:
            if n == 1:
                return None
            else:
                return k
        while(1):
            m.append(k)
            if k.next == None:
                break
            else:
                k = k.next
        
        if len(m)-n-1 != -1:
            m[len(m)-n-1].next = m[len(m)-n].next
        else:
            return m[1]
        r = m[0]
        return r
```