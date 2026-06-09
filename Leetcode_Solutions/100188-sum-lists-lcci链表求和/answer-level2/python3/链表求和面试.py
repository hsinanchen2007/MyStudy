
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        car=0
        lr=l1
        while l1:
            if l2:
                car, res = divmod(l1.val+l2.val+car,10)
                l1.val=res
                pre=l1
                l1=l1.next
                l2=l2.next
            else:
                car, res = divmod(l1.val+car,10)
                l1.val=res
                pre=l1
                l1=l1.next
        pre.next=l2
        while l2:
            car, res = divmod(l2.val+car,10)
            l2.val=res
            pre=l2
            l2=l2.next
        if car:
            tail=ListNode(1)
            pre.next=tail
        return lr
               
```
![image.png](https://pic.leetcode-cn.com/018c954cd50b1b04127fe50623a03e272f748fe8184e6d2bec58885c1b1cfbd3-image.png)
