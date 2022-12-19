### 解题思路
倒数第k个节点，就是距离尾巴距离为k的节点，也就是说尾巴比这个节点领先k个位置。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        fast = head
        slow = head
        while k:
            fast = fast.next
            k -= 1
        while fast:
            fast = fast.next
            slow = slow.next
        return slow.val
        

```