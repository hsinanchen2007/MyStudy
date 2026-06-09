### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        prehead = ListNode(-1)
        #哪个小就指向哪一个，prev带着prehead实现最开始的变化，后面就是Pre变了
        prev = prehead
        #刚开始指向的是l1，等l2小于的时候，prenext指向l2，就实现了连接
        while l1!=None and l2!=None:
            if l1.val < l2.val:
                prev.next = l1
                l1 = l1.next
            else:
                prev.next = l2
                l2 = l2.next

            prev = prev.next

        prev.next = l1 if l1 is not None else l2
        
        #最后返回最开始的节点
        return prehead.next
```