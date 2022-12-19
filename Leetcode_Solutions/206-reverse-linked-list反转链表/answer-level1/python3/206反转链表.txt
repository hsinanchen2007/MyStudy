### 解题思路


### 代码

```python3
#非递归
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        p, pre = head, None
        while p:
            tmp = p.next
            p.next = pre
            pre = p
            p = tmp
        return pre

#递归
#返回的是反转后最后一个节点

class Solution:
    newhead = None
    def reverseList(self, head: ListNode) -> ListNode:
        def helper(p):
            if not p.next:
                self.newhead = p
                return p
            res = helper(p.next)
            res.next = p
            return p
        if not head: return None
        helper(head)
        head.next = None
        return self.newhead

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def helper(p):
            if not p.next:
                return p, p
            newhead, last = helper(p.next)
            last.next = p
            return newhead, p
        if not head: return None
        newhead, last = helper(head)
        last.next = None
        return newhead


```