- 当删除的是第一个节点时，直接返回head.next
- pre指向前一节点，head往后走
- 创建一个新节点new 指向头结点，最后直接返回new.next
- 
![image.png](https://pic.leetcode-cn.com/9722b78e947afda63bda78848db1739f9eeebb71c23793667ae070b3b3cfd315-image.png)

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        pre = ListNode()
        nhead = ListNode()
        pre.next = head
        nhead.next = head
        
        if head.val == val:
            return head.next
        while head:
            if head.val == val:
                pre.next = head.next
            pre = head
            head = head.next
        return nhead.next
```
