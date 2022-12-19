### 解题思路
双指针
不需要判断空指针和单指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head: ListNode, val: int) -> ListNode:
        ans=ListNode(0)
        ans.next=head
        l=ans
        r=ans.next
        while r:
            if r.val==val:
                l.next=r.next
                
            else:
                l=l.next
            r=r.next
        return ans.next
```