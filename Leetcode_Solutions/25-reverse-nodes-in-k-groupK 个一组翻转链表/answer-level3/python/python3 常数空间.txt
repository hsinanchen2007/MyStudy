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
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k < 2: return head
        ph = ListNode(1)
        ph.next = head
        p = ph
        while True:
            i = 0
            if not p: break
            pp = p.next
            while i < k - 1:
                if not pp: break
                pp = pp.next
                i += 1
            
            if not pp:
                break
            #print('first', pp.val)
            first = pp
            nt = first.next
            xh = p.next
            p.next = first
            i -= 1
            while i >= 0:
                q = xh
                for j in range(i):
                    q = q.next
                #print('n', q.val)
                first.next = q
                first = first.next 
                i -= 1
            first.next = nt
            p = first
            
        return ph.next


```