# ```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head
        r, odd, p, head = head, head, head.next, head.next.next
        while head:
            odd.next, head.next, p.next = head, odd.next, head.next
            p, odd, head = p.next, head, p.next and p.next.next
        return r
# ```
# odd 记录上一个奇数位节点，p 记录前一个节点

# 从第3个位置开始循环，每次都把当前节点接到 odd 后面，然后跳到下一个奇数位节点继续循环

# - 😄 更多超短详解请戳[ Github ](https://github.com/cy69855522/Short-LeetCode-Python-Solutions)，交流Q群：902025048，腾讯精选50题已完结，平均每题仅需2.8行代码，欢迎加入我们~