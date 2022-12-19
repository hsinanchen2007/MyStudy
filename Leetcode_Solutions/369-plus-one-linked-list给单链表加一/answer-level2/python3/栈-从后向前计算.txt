### 解题思路
借助栈，从后向前进行进位加法，如果没有进位，可直接退出
如果最前面有进位，增加一个元素即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        stack = []
        pre = ListNode(0)
        pre.next = head
        while head:
            stack.append(head)
            head = head.next
        carry = 0
        cur = stack.pop()
        carry = (cur.val + 1) // 10
        cur.val = (cur.val + 1) % 10
        while stack and carry:
            cur = stack.pop()
            carry = (cur.val + 1) // 10
            cur.val = (cur.val + 1) % 10
        if carry:
            pre.val += 1
            return pre
        else:
            return pre.next
```