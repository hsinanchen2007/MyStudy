> 思路很简单
```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import math
from collections import deque

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        
        n = 0
        cur = root
        while cur:
            n += 1
            cur = cur.next
        
        m1 = math.ceil(n/k)
        m2 = math.floor(n/k)
        ms = [m1]*(n-m2*k)+[m2]*(k+m2*k-n)
        ms = ms[::-1]
        #print(ms)
        
        res = [root]
        cur = root
        cnt = 1
        m = ms.pop(-1)
        while cur:
            if cnt == m:
                next = cur.next
                cur.next = None
                cur = next
                if not cur:
                    break
                res.append(cur)
                cnt = 1
                m = ms.pop(-1)
            else:
                cur = cur.next
                cnt += 1
        #print(res,k,len(res))
        return res+[None]*(k-len(res))
```