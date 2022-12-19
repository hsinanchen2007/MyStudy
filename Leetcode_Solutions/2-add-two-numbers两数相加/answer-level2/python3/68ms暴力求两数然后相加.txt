
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        n1,n2=l1.val,l2.val
        k=10
        while l1.next!=None:
            l1=l1.next
            n1+=l1.val*k
            k*=10
        k=10
        while l2.next!=None:
            l2=l2.next
            n2+=l2.val*k
            k*=10
        n=str(n1+n2)
        temp=None
        for x in n:
            temp,temp.next=ListNode(int(x)),temp
        return temp
```