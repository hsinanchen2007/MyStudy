### 解题思路

注意搞清楚`next`，`cur`，`last`这三个变量即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def helper(last, cur):
            if cur == None: return cur
            next = cur.next
            cur.next = last
            if next == None: return cur
            return helper(cur, next)
        return helper(None, head)
```