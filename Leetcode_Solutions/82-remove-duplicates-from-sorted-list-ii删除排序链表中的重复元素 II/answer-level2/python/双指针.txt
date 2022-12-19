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
        k = ListNode(-1) 
        k.next = head
        p = k
        fla=0
        while p:
            if not p.next:
                break
            q = p.next
            j = q.next
            while j:
                if j.val!=q.val:
                    break
                j = j.next
            if j!=q.next:
                p.next=j
            else:
                p = p.next
        return k.next
            



```