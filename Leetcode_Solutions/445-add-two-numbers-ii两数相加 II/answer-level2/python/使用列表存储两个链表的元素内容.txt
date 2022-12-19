# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        s1, s2 = [], []
        while l1 is not None:
            s1.append(l1.val)
            l1 = l1.next
        while l2 is not None:
            s2.append(l2.val)
            l2 = l2.next
        
        len_1 = len(s1) - 1
        len_2 = len(s2) - 1
        pre = None
        carry = 0
        while len_1 >= 0 or len_2 >= 0 or carry :
            v1 = s1[len_1] if len_1 >= 0 else 0
            v2 = s2[len_2] if len_2 >= 0 else 0
            s = v1 + v2 + carry
            carry = s // 10    
            val = s % 10
            node = ListNode(val)
            node.next = pre
            pre = node
            len_1 -= 1
            len_2 -= 1
        return pre
            