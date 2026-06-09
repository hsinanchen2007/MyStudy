### 解题思路
大佬们，帮我看看我代码的问题和不足之处，谢谢

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head : return 
        cur, pre ,res = 0, head.next, ListNode(head.val)
        while pre:
            cur = pre.next
            pre.next = res
            res = pre
            pre = cur
        return res


        
```