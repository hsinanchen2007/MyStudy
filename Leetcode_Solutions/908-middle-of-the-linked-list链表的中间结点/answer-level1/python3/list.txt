### 解题思路
用个list存储下，返回中间节点就行了。耗费了些存储空间，但是思路简单，运行快速。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        re = []
        while head:
            re.append(head)
            head = head.next
        l = len(re)
        return re[int(l/2)]
```