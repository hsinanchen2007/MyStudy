1. 将链表存入数组

2. 遍历数组前半部分 ，每次从数组尾部获取节点，插入当前节点之后，并修改从尾部获取的节点的next

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        
        p = head
        l = []
        while p:
            l.append(p)
            p = p.next
            
        n = len(l)
        for i in range(n//2):
            l[i].next = l[n-i-1]
            l[n-i-1].next = l[i+1]
            
        if n > 0:
            l[n//2].next = None
```