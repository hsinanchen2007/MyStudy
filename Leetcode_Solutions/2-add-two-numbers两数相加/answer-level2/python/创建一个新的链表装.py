### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1=None, l2=None):
        head=ListNode(0)
        p=head
        count=0
        while l1 or l2:
            if l1==None:
                x=0
            else:
                x=l1.val
            if l2==None:
                y=0
            else:
                y=l2.val
            s=count+x+y
            count=s//10
            node=ListNode(s%10)
            p.next=node
            p=node
            if l1!=None:
                l1=l1.next
            if l2!=None:
                l2=l2.next
        if count!=0:
            node=ListNode(1)
            p.next=node
            return head.next
        else:
            return head.next

        
            

        
        





            


        

```