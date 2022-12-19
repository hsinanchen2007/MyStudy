
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans=l1
        car=0
        while l1 and l2:
            car,l1.val=divmod(l1.val+l2.val+car,10)
            ptr=l1
            l1=l1.next
            l2=l2.next 
        if l2:
            ptr.next=l2
            ptrl=l2
        else:
            ptrl=l1
        while ptrl:
            car,ptrl.val=divmod(ptrl.val+car,10)
            ptr=ptrl
            ptrl=ptrl.next
        if car:
            f=ListNode(car)
            ptr.next=f
        return ans
```

![image.png](https://pic.leetcode-cn.com/2bee5eb522e1873d4ee859785206e128ac83278092f48af72d6f0121e9a71268-image.png)
