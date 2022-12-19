### 解题思路
此处撰写解题思路
双指针，，真的很简单。。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        s,f = head,head
        while f and f.next:
            s = s.next
            f = f.next.next
        return s
```