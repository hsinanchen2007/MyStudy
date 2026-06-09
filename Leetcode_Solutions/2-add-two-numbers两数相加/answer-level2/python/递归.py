```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode, s=0) -> ListNode:
        newSum = l1.val + l2.val + s  
        l1.val = newSum%10
        if (l1.next or l2.next): 
            l1.next = self.addTwoNumbers(l1.next or ListNode(0),l2.next or ListNode(0), newSum//10)
        elif newSum >= 10:
            l1.next = ListNode(1)
        return l1
```
