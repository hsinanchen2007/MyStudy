### 解题思路
一个快指针一个慢指针，速度为2倍，快指针到末尾，满指针则在终点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        
        cur = head
        pre = cur
               
        while cur and cur.next:
            cur=cur.next
            if cur.next :
                cur=cur.next
                pre=pre.next
            else: 
                pre=pre.next
        return pre
```