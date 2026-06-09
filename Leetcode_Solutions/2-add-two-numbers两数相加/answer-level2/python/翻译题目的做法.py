### 解题思路
会浪费一个节点的内存

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        head1, head2 = l1, l2
        p = ListNode(-1)
        res = p 
        flag=0 #进位
        while(head1 and head2):          
            res.next = ListNode((head1.val+head2.val+flag)%10)
            flag = (head1.val+head2.val+flag)//10   
            res,head1,head2 = res.next,head1.next,head2.next
                
        while head2:
            res.next = ListNode((head2.val+flag)%10)
            flag = (flag+head2.val)//10
            res,head2 = res.next,head2.next
        while head1:
            res.next = ListNode((head1.val+flag)%10)
            flag = (flag+head1.val)//10
            res,head1 = res.next,head1.next
        if flag:
            res.next = ListNode(1)
        return p.next
```