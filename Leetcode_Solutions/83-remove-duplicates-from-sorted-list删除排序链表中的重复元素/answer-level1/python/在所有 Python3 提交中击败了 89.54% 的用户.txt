### 解题思路
此处撰写解题思路
易错点：
1、没有判断是否为空
2、循环结束后没有将tail的后面清空
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head
        tail , node = head, head.next
        while node:
            if tail.val == node.val :
                node = node.next
            else:
                tail.next = node
                tail = node 
                node = tail.next
        tail.next = None
        return head
```