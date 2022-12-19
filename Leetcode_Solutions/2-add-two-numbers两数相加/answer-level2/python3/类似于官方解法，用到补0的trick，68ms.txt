### 解题思路
在进行加法的同时，检查是否下一次会出现一个有后续一个没后续的情况，如果是，则给没后续的那个补0

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        l3 = head
        extra_add = False
        while(l1!= None and l2!=None):
            val = l1.val + l2.val
            if(val>=10):
                val-=10
                if l1.next:
                    l1.next.val+=1
                elif l2.next:
                    l2.next.val+=1
                else:
                    extra_add = True
            l3.next = ListNode(val)
            l1 = l1.next
            l2 = l2.next
            l3 = l3.next
            if l1 and l2==None:
                l2 = ListNode(0)
            if l2 and l1==None:
                l1 = ListNode(0)
        if extra_add:
            l3.next = ListNode(1)
        return head.next
```