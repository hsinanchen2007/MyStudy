### 解题思路
思路来自贪吃蛇大作战

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # print(l1)
        # print(l2)
        # res = ListNode()
        if l1 is None and l2 is None:
            return
        elif l1 is None:
            if l2.val < 10:
                return l2
            else:
                res = ListNode(l2.val % 10)
                if l2.next is None:
                    l2.next = ListNode(1)
                else:
                    l2.next.val += 1
                res.next = self.addTwoNumbers(l1, l2.next)
                return res
        elif l2 is None:
            if l1.val < 10:
                return l1
            else:
                res = ListNode(l1.val % 10)
                if l1.next is None:
                    l1.next = ListNode(1)
                else:
                    l1.next.val += 1
                res.next = self.addTwoNumbers(l1.next, l2)
                return res
        elif (l1.val + l2.val) < 10:
            res = ListNode(l1.val + l2.val)
            res.next = self.addTwoNumbers(l1.next, l2.next)
            return res
        else:
            res = ListNode((l1.val + l2.val) % 10)
            if l1.next is None and l2.next is None:
                l1.next = ListNode(1)
                # l1.next.val = 1
            elif l1.next is None:
                l2.next.val += 1
            elif l2.next is None:
                l1.next.val += 1
            else:
                l1.next.val += 1
            res.next = self.addTwoNumbers(l1.next, l2.next)
            return res
        
```