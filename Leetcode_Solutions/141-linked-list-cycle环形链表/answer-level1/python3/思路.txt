### 解题思路
创建一个set集合，通过寻找head是否存在集合中

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        myset= set()
        while head:
            if (head in myset):
                return True
            myset.add(head)
            head = head.next
        return False
```