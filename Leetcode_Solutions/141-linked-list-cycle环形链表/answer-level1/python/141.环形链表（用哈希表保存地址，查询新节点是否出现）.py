### 解题思路
依次遍历链表，每次的地址存在哈希表中（使用set集合），然后在查询新节点是否出现过

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        cur = head
        buf = set()
        while cur and cur.next:
            buf.add(cur)
            if cur.next in buf:
                return True
            cur = cur.next
        return False
```