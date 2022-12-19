

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:
        pre=ListNode(0)
        pre.next=head
        ptr=head
        vs=set()
        while ptr:
            if ptr.val in vs:
                pre.next=ptr.next
                ptr=ptr.next
            else:
                vs.add(ptr.val)
                pre=ptr
                ptr=ptr.next
        return head
```
![image.png](https://pic.leetcode-cn.com/c52d5b3da974fc8a58ff2e3b449c8adf7bdb174345bedd0a0641c505b2cecb65-image.png)
