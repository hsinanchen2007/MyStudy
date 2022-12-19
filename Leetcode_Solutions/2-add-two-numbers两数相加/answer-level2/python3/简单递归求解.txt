### 解题思路
1. 将单链表转成整数
2. 求和
3. 将结果转成单链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def num(v):
            if v.next==None:
                return v.val
            return v.val + num(v.next)*10

        def getList(v):
            if v//10 == 0:
                return ListNode(v)
            a = ListNode(v%10)
            a.next = getList(v//10)
            return a

        return getList(num(l1)+num(l2)) 
```