### 解题思路
carry=sum//10
双斜线是取整，此处要取整，单斜线会算小数部分导致报错

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pre=cur=ListNode(0)
        carry=0
        while l1!=None or l2!=None:
            x=0 if l1==None else l1.val
            y=0 if l2==None else l2.val
            sum=x+y+carry
            carry=sum//10
            sum=sum%10
            cur.next=ListNode(sum)
            cur=cur.next
            if l1!=None:
                l1=l1.next
            if l2!=None:
                l2=l2.next
        if carry!=0:
            cur.next=ListNode(carry)
        return pre.next







```