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
    def reversePrint(self, head: ListNode) -> List[int]:
        p = head
        a = []
        b = []
        while p != None:
            a.append(p.val)
            p = p.next
        for i in reversed(range(len(a))):
            b.append(a[i])
        return b


```