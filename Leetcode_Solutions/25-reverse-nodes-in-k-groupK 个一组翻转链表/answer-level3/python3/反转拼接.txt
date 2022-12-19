### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        n = 0
        ph = head
        while ph:
            n += 1
            ph = ph.next
        if n <= 1 or k == 1:
            return head
        m, q = n // k, n % k
        ans = ListNode(0)
        ans.next = head
        pa, ph = ans, head
        for _ in range(m):
            pre, nex = None, None
            for _ in range(k):
                nex = ph.next
                ph.next = pre
                pre = ph
                ph = nex
            pa.next = pre
            for _ in range(k):
                pa = pa.next
        pa.next = nex
        return ans.next
```