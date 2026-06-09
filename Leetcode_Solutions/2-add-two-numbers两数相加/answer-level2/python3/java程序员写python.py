`# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        head=ListNode(0)
        l = head
        carry=0
        while l1 or l2:
            x = l1.val if l1 else 0
            y = l2.val if l2 else 0
            temp = x + y + carry;
            ret = temp%10
            carry = temp // 10;
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next; 
            l.next = ListNode(ret)
            l = l.next
        if carry > 0:
            l.next = ListNode(carry)
        return head.next;
`