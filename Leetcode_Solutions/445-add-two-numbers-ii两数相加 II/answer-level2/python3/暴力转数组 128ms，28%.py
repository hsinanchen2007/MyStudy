暴力转数组 128ms，28%

    class Solution:
        def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
            a = []
            b = []
            s1, s2 = l1, l2
            while l1:
                a.append(l1.val)
                l1 = l1.next
            while l2:
                b.append(l2.val)
                l2 = l2.next
            
            a1 = len(a)
            b1 = len(b)
            
            c = []
            add = 0
            while a1>0 and b1>0:
                plus = a[a1-1]+b[b1-1]+add
                c.append(plus%10)
                add = plus//10
                a1 -= 1
                b1 -= 1
            while a1>0:
                plus = a[a1-1]+add
                c.append(plus%10)
                add = plus//10
                a1 -=1
            while b1>0:
                plus = b[b1-1]+add
                c.append(plus%10)
                add = plus//10
                b1 -=1
            if add >0:
                c.append(add)
            
            c1 = len(c)
            target = ListNode(0)
            p = target
            while c1>0:
                p.next = ListNode(c[c1-1])
                p = p.next
                c1 -=1

            return target.next
            
