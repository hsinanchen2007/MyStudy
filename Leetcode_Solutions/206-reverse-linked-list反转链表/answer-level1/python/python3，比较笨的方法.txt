### 解题思路
可能我这个方法比较笨。。。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        if head.next==None:
            return head

        res=[]
        while head:
            res.append(head)
            head=head.next
        a=res.pop()
        p=res.pop()
        a.next=p
        while res:
            p.next=res.pop()
            p=p.next
        p.next=None
        return a

        
```