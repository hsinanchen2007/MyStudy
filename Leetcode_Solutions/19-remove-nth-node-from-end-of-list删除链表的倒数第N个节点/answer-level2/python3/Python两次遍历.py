### 解题思路
先计算长度再删除
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        node = head
        num = 1
        while(node.next):
            node = node.next
            num += 1
        if(num == n):
            return head.next
        node = head
        for i in range(num - n - 1):
            node = node.next
        node.next = node.next.next
        return head
```