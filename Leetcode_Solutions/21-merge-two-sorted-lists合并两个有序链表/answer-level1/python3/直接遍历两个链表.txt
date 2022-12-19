### 解题思路
此处撰写解题思路
1. 构建一个中间链表和一个哑链表，哑链表指向中间链表的地址
2. 中间链表指向两个链表的最小元素
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 == None:
            return l2
        elif l2 == None:
            return l1
        temp = ListNode(0)
        node = temp
        max_val = pow(2, 31)
        while l1 != None or l2 != None:
            v1 = l1.val if l1 != None else max_val
            v2 = l2.val if l2 != None else max_val
            if v1 >= v2:
                temp.next = ListNode(v2)
                l2 = l2.next
            else:
                temp.next = ListNode(v1)
                l1 = l1.next
            temp = temp.next
            
        return node.next

```