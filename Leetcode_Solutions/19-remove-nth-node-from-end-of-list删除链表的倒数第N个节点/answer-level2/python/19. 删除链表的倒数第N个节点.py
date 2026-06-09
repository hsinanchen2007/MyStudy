### 解题思路
双指针法
- 先让`P1`跑N个节点，然后`P1` `P2`一块遍历，当`P1`为`None`时即停下

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        new_head = ListNode(-1)
        new_head.next = head
        p1 = new_head
        p2 = new_head
        res = new_head
        while n >= 0:
            p1 = p1.next
            n -= 1
        while p1:
            p1 = p1.next
            p2 = p2.next
        p2.next = p2.next.next
        return res.next
        
```