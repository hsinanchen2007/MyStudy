```
#!/usr/bin/python
#-*- coding:utf-8 -*-

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        # 把数字的每一位都存起来
        result = []
        # 进位
        step = 0
        while l1 and l2:
            tmp = l1.val + l2.val + step
            if tmp >= 10:
                tmp -= 10
                step = 1
            else:
                step = 0
            result.append(tmp)
            l1 = l1.next
            l2 = l2.next

        # 有可能存在进位 但是l1 和 l2都为空了
        if step:
            if l1:
                l1.val += step
            elif l2:
                l2.val += step
            else:
                # [5] [5] 加完以后都是为null了，但是step有值
                l1 = ListNode(step)
            step = 0

        while l1:
            if l1.val >= 10:
                result.append(l1.val - 10)
                if l1.next:
                    l1.next.val += 1
                else:
                    l1.next = ListNode(1)
            else:
                result.append(l1.val)

            l1 = l1.next

        while l2:
            if l2.val >= 10:
                result.append(l2.val - 10)
                if l2.next:
                    l2.next.val += 1
                else:
                    l2.next = ListNode(1)
            else:
                result.append(l2.val)

            l2 = l2.next

        node = ListNode(None)
        tmp = node
        for item in result:
            node.next = ListNode(item)
            node = node.next

        return tmp.next

if __name__ == '__main__':
    l1 = ListNode(2)
    l1.next = ListNode(4)
    l1.next.next = ListNode(3)

    l2 = ListNode(5)
    l2.next = ListNode(6)
    l2.next.next = ListNode(4)

    s = Solution()
    s.addTwoNumbers(l1, l2)
```
