### 解题思路
非常简单的将listnode中所有node放入一个列表，返回倒数第k个即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if head == None:
            return head
        nodes = []
        while head != None:
            nodes.append(head)
            head = head.next
        return nodes[-k]
```
