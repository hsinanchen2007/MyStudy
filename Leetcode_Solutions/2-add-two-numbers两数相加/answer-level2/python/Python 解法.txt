### 解题思路
此处撰写解题思路

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
        t1 = 0
        i = 0
        if l1 is None: return l2
        if l2 is None: return l1

        while(l1):
            t1 = t1+l1.val*(10**i)
            i+=1
            l1 = l1.next

        t2 = 0
        i=0
        while(l2):
            t2 = t2+l2.val*(10**i)
            i+=1
            l2 = l2.next

        t3 = t1+t2
        
        dummy_list = ListNode(0)
        cur =dummy_list 
        if t3 == 0:
            return ListNode(0)
        while(t3):
            cur.next = ListNode(t3%10)
            t3 = int(t3)//10
            cur = cur.next

        return(dummy_list.next)
```