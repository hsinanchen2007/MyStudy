### 解题思路
将链表的数字转换之后存到num1，num2中，求完和后在转换为链表

### 代码

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1,num2=0,0
        while l1:
            num1=num1*10+l1.val
            l1=l1.next
        while l2:
            num2=num2*10+l2.val
            l2=l2.next
        res=num1+num2
        pre=None
        if res==0:
            return ListNode(0)
        while res:
            cur=ListNode(res%10)
            cur.next=pre
            pre=cur
            res//=10
        return pre
        

```