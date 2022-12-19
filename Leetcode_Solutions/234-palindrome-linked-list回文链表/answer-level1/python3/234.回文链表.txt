### 解题思路
- 读出链表的值，存入列表
- 复制一份列表然后反转
- 若列表及其反转相等则返回True,否则返回False

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        string = []
        while head:
            string.append(head.val)
            head = head.next
        s = string[::]
        s.reverse()
        return string == s

```