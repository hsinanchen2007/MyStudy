    # Definition for singly-linked list.
    # class ListNode:
    #     def __init__(self, x):
    #         self.val = x
    #         self.next = None

    class Solution:
        def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
            a = []
            b = []
            while l1:
                a.append(l1.val)
                l1 = l1.next
            while l2:
                b.append(l2.val)
                l2 = l2.next
            
            t = []
            add = 0
            while a and b:
                plus = a.pop()+b.pop()+add
                t.append(plus%10)
                add = plus//10
            
            while a:
                plus = a.pop()+add
                add = plus//10
                t.append(plus%10)
            while b:
                plus = b.pop()+add
                add = plus//10
                t.append(plus%10)
            if add:
                t.append(add)
            
            target = ListNode(None)
            p = target
            while t:
                p.next = ListNode(t.pop())
                p = p.next
            
            return target.next
                
                
            
                
