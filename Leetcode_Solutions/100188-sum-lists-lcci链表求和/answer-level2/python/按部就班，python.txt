### 解题思路
先转换链表，再转换数字

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
        def get_number(l):
            result=0
            pos=1
            while l:
                result=result+l.val*pos
                pos=pos*10
                l=l.next
            return result
        result=get_number(l1)+get_number(l2)
        print result

        def make_list(num):
            result=ListNode(0)
            rr=result
            if num==0:
                return ListNode(0)
            while num:
                result.next=ListNode(num%10)
                num=num/10
                result=result.next
            return rr.next

        return make_list(result)
                
```