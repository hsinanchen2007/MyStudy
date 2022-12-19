```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        res = ListNode(-1)  # 新建一个只有一个节点的链表，节点值为-1
        temp = res  # 新建临时节点，防止移动res的指针
        while l1 and l2:
            if l1.val <= l2.val:  # 若l1当前节点值小于l2当前节点值
                temp.next = l1  # 将temp的小一节点连到l1上
                l1 = l1.next  # l1跳到下一节点
            else:  # 否则连到l2上
                temp.next = l2
                l2 = l2.next
            temp = temp.next  # temp跳到下一节点
        
        if l1:  # 连接最后一个节点
            temp.next = l1
        else:
            temp.next = l2
            
        
        return res.next  # 去掉res的头结点
   
```
