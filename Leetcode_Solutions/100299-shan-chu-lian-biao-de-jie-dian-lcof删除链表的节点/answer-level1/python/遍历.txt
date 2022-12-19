### 解题思路

执行用时 :36 ms, 在所有 Python3 提交中击败了96.71% 的用户
内存消耗 :14 MB, 在所有 Python3 提交中击败了100.00%的用户

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        if head.val == val:
            return head.next
        res = head
        while head:
            pre = head
            if head.next and head.next.val == val:
                pre.next = head.next.next
            head = head.next
        return res
            
            
```