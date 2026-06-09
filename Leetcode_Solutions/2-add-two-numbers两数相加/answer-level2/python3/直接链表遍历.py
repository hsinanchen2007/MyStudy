### 解题思路
此处撰写解题思路
如果l1 和l2 都为None了，那么直接退出循环，否则当l1或l2为none时，则直接将其赋值为ListNode(0)
新链表的值直接相加即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = l1
        carry = 0

        while True:
            c = l1.val + l2.val + carry
            l1.val, carry = c % 10, c // 10

            if not l1.next and not l2.next:
                break
            
            if not l1.next:
                l1.next = ListNode(0)
            elif not l2.next:
                l2.next = ListNode(0)

            l1 = l1.next
            l2 = l2.next
        
        if carry:
            l1.next = ListNode(1)
        
        return result
            
        
        
```