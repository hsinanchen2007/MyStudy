```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        def gen(n):
            while n: yield n.val; n = n.next
        return [*gen(head)] == [*gen(head)][::-1]
```

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        s, f, p = head, head, None
        while f and f.next:
            s.next, p, s, f = p, s, s.next, f.next.next
        if f: s = s and s.next
        while s and p and s.val == p.val:
            p, s = p.next, s.next
        return s == p == None
```
- f 记录快指针，每次走倆步，s 记录慢指针，每次走一步，p 记录 s 的前一个节点
- 首先使用快慢指针找到中点，第一个 while 停止时如果链表长度为奇数，s 为中点；否则 f 为 None，s 为右半部分的第一个节点
- 若链表长度为奇数，s 前进一步，然后 p 和 s 往俩个方向同时遍历比对是否回文