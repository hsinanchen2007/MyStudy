### 解题思路
现将两个链表转为10进制整数
两数相加得到结果
将结果转换为链表，返回链表
### 代码

```python
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
        num1 = 0
        num2 = 0
        i = 0

        while l1:
            num1 += l1.val * pow(10, i)
            i += 1
            l1 = l1.next

        i = 0

        while l2:
            num2 += l2.val * pow(10, i)
            i += 1
            l2 = l2.next

        tmp = num1 + num2
        p1 = ListNode(tmp % 10)
        res = p1
        tmp = tmp // 10
        
        while tmp:
            p1.next = ListNode(tmp % 10)
            tmp = tmp // 10
            p1 = p1.next
        
        return res
```