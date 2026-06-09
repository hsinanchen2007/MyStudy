### 解题思路
先计算链表的长度，再遍历到链表长度的一半

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        l = 0
        cur = head
        while cur:
            l += 1
            cur = cur.next
        res = 0
        while res < l//2:
            head = head.next
            res += 1

        return head
```