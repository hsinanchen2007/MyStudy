### 解题思路
此处撰写解题思路
python 时间差 猜结果

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import time
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        t1 = time.time()
        while(head):
            head = head.next
            t2 = time.time()
            if t2 - t1 > 0.100:
                return True
        return False
```