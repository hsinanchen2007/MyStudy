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
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        '''
        if head == None or head.next == None:
            return head
        p = head
        while p.next != None and p.val != None:
            if p.val == p.next.val:
                p.next = p.next.next
            else:
                p = p.next
        return head
        '''
        '''
        if head==None or head.next==None:
            return head
        p = head
        while True:
            if p.val==p.next.val:
                p.next=p.next.next
            else:
                p = p.next
            if p.next==None:
                break
        return head
        '''
        if not (head and head.next):
            return head
        i,j = head,head
        while j:
            if i.val!=j.val:
                i = i.next
                i.val = j.val
            j = j.next
        i.next = None
        return head
```