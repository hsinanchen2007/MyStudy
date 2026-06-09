### 解题思路
首先实现两个空列表来装链表数据，再写个链表头插入方法

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        a = []
        b = []
        while l1:
            a.append(l1.val)
            l1 = l1.next
        while l2:
            b.append(l2.val)
            l2 = l2.next
        c = str(int(''.join([str(i) for i in a[::-1]])) + int(''.join([str(i) for i in b[::-1]])))
        return self.head_list(c)
            
    def head_list(self,s):
        head = ListNode(int(s[0]))
        for i in s[1:]:
            node = ListNode(int(i))
            node.next = head
            head = node

        return head



```