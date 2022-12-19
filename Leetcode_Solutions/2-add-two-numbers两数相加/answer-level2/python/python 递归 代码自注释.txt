大体思路就是遍历l1、l2和l1.next、l2.next是否为None的各种场景，再递归调用。

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is not None and l2 is not None:
            val = (l1.val + l2.val)%10
            flag = (l1.val + l2.val)/10
            a = ListNode(val)

            if l1.next is not None and l2.next is not None:
                l1.next.val += flag
                a.next = self.addTwoNumbers(l1.next , l2.next)
            elif l1.next is None and l2.next is not None:
                l2.next.val += flag
                a.next = self.addTwoNumbers(l1.next, l2.next)
            elif l2.next is None and l1.next is not None:
                l1.next.val += flag
                a.next = self.addTwoNumbers(l1.next, l2.next)
            else:
                if flag == 1:
                    b = ListNode(1)
                    a.next = b
                return a
            
        elif l1 is None and l2 is not None:
            val = l2.val%10
            flag = l2.val/10
            a = ListNode(val)

            if l2.next is not None:
                l2.next.val += flag
                a.next = self.addTwoNumbers(None, l2.next)
            else:
                if flag == 1:
                    b = ListNode(1)
                    a.next = b
                return a


        elif l2 is None and l1 is not None:
            val = l1.val%10
            flag = l1.val/10
            a = ListNode(val)

            if l1.next is not None:
                l1.next.val += flag
                a.next = self.addTwoNumbers(l1.next, None)
            else:
                if flag == 1:
                    b = ListNode(1)
                    a.next = b
                return a
        
        return a
        