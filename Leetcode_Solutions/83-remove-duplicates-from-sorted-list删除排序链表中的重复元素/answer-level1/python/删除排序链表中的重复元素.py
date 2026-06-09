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
        k = head
        if k == None:
            return None
        if k.next == None:
            return k
        l = k.next
        while(k != None):
            if k.next != None:
                while(k.val == l.val):
                    k.next = l.next
                    l = l.next
                    if l == None:
                        break
                if l == None:
                    break
                k = l
                l = k.next
            else:
                break
        
        return head
```