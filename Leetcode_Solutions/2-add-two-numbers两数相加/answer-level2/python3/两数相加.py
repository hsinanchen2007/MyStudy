### 解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        res1=0
        k1=0
        head1=l1
        while head1:
            res1+=head1.val*(10**k1)
            k1+=1
            head1=head1.next
        res2=0
        k2=0
        head2=l2
        while head2:
            res2+=head2.val*(10**k2)
            k2+=1
            head2=head2.next
        result=res1+res2
        head=ListNode(0)
        cur=head
        n=len(str(result))
        for i in range(n):
            res_next=result%10
            cur.next=ListNode(res_next)
            result=result//10
            cur=cur.next
        return head.next  
```