没想到写起来会这么繁琐，思考的点还是很多的，好在效果还可以。比如如何创建一个链表，以及如何处理l1 >> l2的情况等等。下面对在时间上的优化做了注释

执行用时 : 68 ms, 在Add Two Numbers的Python提交中击败了85.35% 的用户
内存消耗 : 11.8 MB, 在Add Two Numbers的Python提交中击败了27.89% 的用户

```python []
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
        c1 = l1
        c2 = l2
        l3 = ListNode(0)
        c3 = l3
        jinwei = 0
        while c1 or c2:
            if c1 and c2:
                cur = jinwei + c1.val + c2.val
                jinwei = cur // 10
                yushu = cur % 10
                c3.next = ListNode(yushu)
                c1 = c1.next
                c2 = c2.next
                c3 = c3.next
            elif c1:
                if jinwei:
                    cur = jinwei + c1.val
                    jinwei = cur // 10
                    yushu = cur % 10
                    c3.next = ListNode(yushu)
                    c1 = c1.next
                    c3 = c3.next
                else:
                    c3.next = c1
                    break //如果一个链表遍历完成，并且不存在进位了，就可以跳出
            elif c2:
                if jinwei:
                    cur = jinwei + c2.val
                    jinwei = cur // 10
                    yushu = cur % 10
                    c3.next = ListNode(yushu)
                    c2 = c2.next
                    c3 = c3.next
                else:
                    c3.next = c2
                    break //如果一个链表遍历完成，并且不存在进位了，就可以跳出
        if jinwei:
            c3.next = ListNode(1)
                    
        return l3.next 
```
