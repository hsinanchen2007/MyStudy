### 解题思路
使用字典存储已经过的结点。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        pos = set()
        ptr = headA
        while ptr:
            pos.add(ptr)
            ptr=ptr.next
        ptr=headB
        while ptr:
            if ptr in pos:
                return ptr
            ptr=ptr.next
        return None
```

![image.png](https://pic.leetcode-cn.com/97a7457dd0b262fe03b002aa505b29c05567571c9ddc4ca5e11c4036ae2a64f2-image.png)
