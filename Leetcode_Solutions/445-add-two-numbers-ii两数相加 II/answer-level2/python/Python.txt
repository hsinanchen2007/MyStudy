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
        newhead=ListNode(-1)

        stack1=[]
        stack2=[]
        head1=l1
        head2=l2
        while(l1!=None):
            stack1.append(l1.val)
            l1=l1.next
        while(l2!=None):
            stack2.append(l2.val)
            l2=l2.next



        temp=0
        while(len(stack1)!=0 or len(stack2)!=0 or temp!=0):
            if len(stack1)==0 and len(stack2)==0 and temp==1:
                ans=temp
                temp=0
                cur=ListNode(ans)
                cur.next=newhead.next
                newhead.next=cur
            elif len(stack1)!=0 and len(stack2)!=0:
                ans=stack1.pop()+stack2.pop()+temp
                temp=int(ans/10)
                ans=ans%10
                cur=ListNode(ans)
                cur.next=newhead.next
                newhead.next=cur
            elif len(stack1)!=0:
                ans=stack1.pop()+temp
                temp=int(ans/10)
                ans=ans%10
                cur=ListNode(ans)
                cur.next=newhead.next
                newhead.next=cur
            else:
                ans=stack2.pop()+temp
                temp=int(ans/10)
                ans=ans%10
                cur=ListNode(ans)
                cur.next=newhead.next
                newhead.next=cur
        return newhead.next
```