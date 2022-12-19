题目有几个技巧与陷阱要考虑：
1. 一个链表为空的时候
2. 值是 (x+y+carry)%10 而不是(x+y)%10+carry ,考虑9 与1->9 相加的情况，会输出 0，10
3. 考虑最后一次相加会进1的情况，样本是9 与1->9 相加
4. 技巧：一个链表为空后，val 直接闲置为0 即可。
5. 题目的输入是链表节点而不是python list，for i in l1: 这种写法是错误的。

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
      
        if l1 is None: 
            return l2
        if l2 is None:
            return l1
        result = ListNode(0)
        return_result = result
        carry = 0
        p = l1
        q = l2
        
        while(p is not None or q is not None):
            if p is None:
                x = 0
            else :
                x = p.val
            if q is None:
                y = 0
            else :
                y = q.val   
            result.val = (x+y+carry)%10 # Trap : not (x+y)%10+carry
            carry = (x+y+carry)/10   #同上
            if p is not None:
                p = p.next
            if q is not None:
                q = q.next
            if p is not None or q is not None: #注意考虑什么时候创建下一个节点，避免尾部多一个0的情况
                result.next = ListNode(0)
                result =  result.next
        if carry == 1:
            result.next = ListNode(1)
           
        return return_result 
    
    
    
                
            
```