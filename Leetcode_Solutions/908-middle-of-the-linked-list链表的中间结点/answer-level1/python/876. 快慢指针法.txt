### 解题思路
1. 慢指针每次走一步，快指针每次走两步，一因此快指针走的距离将是慢指针的两倍
2. 当快指针遍历到链表末尾时，慢指针指向即为中间节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        p = head
        q = head
        while q != None and q.next != None:
            p = p.next
            q = q.next.next
        
        return p
```