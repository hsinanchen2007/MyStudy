### 解题思路
..纯粹按照加法步骤写出来的，一位一位的往上加，判断是否有进位

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l3 = ListNode(0)
        l4 = l3
        tmp = 0
        while True:
            if (l1 != None and l2 != None) :
                l3.val = (l1.val + l2.val + tmp)%10
                tmp = (l1.val + l2.val + tmp)//10
                l1 = l1.next
                l2 = l2.next
            elif l2 != None:
                l3.val = (l2.val + tmp)%10
                tmp = (l2.val + tmp)//10
                l2 = l2.next
            elif l1 != None:
                l3.val = (l1.val + tmp)%10
                tmp = (l1.val + tmp)//10
                l1 = l1.next
            else:
                return l4
            if l1 != None or l2 != None:
                l3.next = ListNode(0)
                l3 = l3.next
            elif tmp == 1:
                l3.next = ListNode(1)

```