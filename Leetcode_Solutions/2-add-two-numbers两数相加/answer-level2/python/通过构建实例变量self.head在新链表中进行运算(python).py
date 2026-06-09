造一个结点的开头，链接之后的结点。
新链表每个结点的值等于旧链表的两个结点值的和。
如果大于或等于10，则进1位，即下个结点的初始值为1。
以下为代码：
```
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def __init__(self):
        self.head=ListNode(0)

    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        p=self.head
        while l1 or l2:
            if l1 is None:#没值的话默认零
                l1 = ListNode(0)
            if l2 is None:
                l2=ListNode(0)
            a=l1.val+l2.val
            if p.next is None:#第一次或者之前的和小于10
                if a < 10:
                    p.next=ListNode(a)
                else:#本次和大于或等于10
                    p.next = ListNode(a - 10)
                    p.next.next = ListNode(1)
            else:#之前的和大于或等于10
                p.next.val+=a
                if p.next.val>=10:#本次和又大于或等于10
                    p.next = ListNode(p.next.val - 10)
                    p.next.next = ListNode(1)
            p=p.next
            l1=l1.next
            l2=l2.next
        return self.head.next
```

