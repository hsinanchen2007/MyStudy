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
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head ==None:
            return None
        
        l = head
        n = 0
        while l:
            l = l.next
            n +=1
        k = k%n
        
        q,p = head,head
        while k>0:
            q = q.next
            k-=1
        while(q.next):
            q = q.next
            p = p.next
        q.next = head
        head = p.next
        p.next = None

        return head
```