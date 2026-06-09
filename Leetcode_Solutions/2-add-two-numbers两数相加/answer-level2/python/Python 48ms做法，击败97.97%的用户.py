参考了其他人的做法，不新建链表，靠修改l1的值来完成，l1不够长就把l2接上。理论上讲内存应该能少占些，但是并没有降，不知道是怎么回事

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1:
            head = l1
        else:
            head = l2
        flag = 0
        while l1:
            if l2:
                val2 = l2.val
                l2 = l2.next
            else:
                val2 = 0
            value = (flag + l1.val + val2) % 10
            flag  = (flag + l1.val + val2) / 10
            l1.val = value
            if not l1.next:
                break
            l1 = l1.next
            
        if l2 or flag:
            l1.next = l2
            while flag:
                if not l1.next:
                    l1.next = ListNode(0)
                l1 = l1.next
                value = (l1.val + flag) % 10
                flag = (l1.val + flag) / 10
                l1.val = value
        return head
```
