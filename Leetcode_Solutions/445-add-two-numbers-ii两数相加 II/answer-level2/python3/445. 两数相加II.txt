### 解题思路
我这有点不要碧莲的作法。。。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_str = l2_str = ""
        while l1:
            l1_str+=str(l1.val)
            l1=l1.next
        while l2:
            l2_str+=str(l2.val)
            l2=l2.next
        res = str(int(l1_str)+int(l2_str))
        head = ListNode(int(res[0]))
        tmp = head
        for i in range(1,len(res)):
            tmp.next = ListNode(int(res[i]))
            tmp=tmp.next
        return head

```