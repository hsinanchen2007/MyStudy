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

        # 存放结果
        result = ListNode(0)
        
        def recursion(l1, l2, carry,result):
            # 全部都为空就退出
            if not (l1 or l2): 
                # 如果还有进位就加1
                if carry: result.next = ListNode(1) 
                return result
            # 两个相加的数、默认为0
            l1_0 = l2_0 = 0
            # 下一次要计算的数、默认为None
            l1_next = l2_next= None
            # 不为空，则将val和next取出来进行本次利用
            if l1: 
                l1_0 = l1.val
                l1_next = l1.next
            if l2: 
                l2_0 = l2.val
                l2_next = l2.next
                
            # 和为两个数加上次的进位
            sum_temp = l1_0 + l2_0 + carry
            # 和满十，则进一，并且取模
            if sum_temp >= 10:
                carry = 1
                sum_temp %= 10
            else:  # 不满十，进位为0
                carry = 0
                
            # 将本次的和添加进结果
            result.next = ListNode(sum_temp)
            # 带上进位进行递归
            recursion(l1_next, l2_next, carry,result.next)
        
        # 将两个表进行递归
        recursion(l1, l2, 0,result)
        return result.next[[[]()]()]()
```
