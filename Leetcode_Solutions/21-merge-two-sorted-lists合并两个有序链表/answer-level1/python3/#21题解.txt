### 解题思路1
递归

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        elif l1.val<l2.val:
            l1.next=self.mergeTwoLists(l1.next,l2)
            return l1
        else:
            l2.next=self.mergeTwoLists(l1,l2.next)
            return l2
```
### 解题思路1
迭代

### 代码
```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = point = ListNode(0)
                while l1 and l2:
                    if l1.val <= l2.val:
                        point.next = l1
                        l1 = l1.next
                    else:
                        point.next = l2
                        l2 = l1
                        l1 = point.next.next
                    point = point.next
                if not l1:
                    point.next=l2
                else:
                    point.next=l1
                return head.next
```
