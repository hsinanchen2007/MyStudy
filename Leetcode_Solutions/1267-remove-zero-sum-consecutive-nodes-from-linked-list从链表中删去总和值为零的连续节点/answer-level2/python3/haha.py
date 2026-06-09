```
class ListNode():
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        if head == None:
            return []

        t = ListNode(None)
        pre = t
        pre.next = head
        start = head
        d = []
        while pre:
            sum1 = 0
            flag = 0
            while start:
                sum1 += start.val
                if sum1 == 0:
                    flag = 1
                    print(pre.val)
                    pre.next = start.next
                    start = start.next
                    break
                else:
                    start = start.next
            if flag == 0:
                pre = pre.next
                if pre==None:
                    break
                start = pre.next
        return t.next

```
