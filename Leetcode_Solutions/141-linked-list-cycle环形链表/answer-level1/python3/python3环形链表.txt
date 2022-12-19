
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        if head:
            i=0
            ptr=head.next
            while ptr and not isinstance(ptr,int):
                head.next=i
                i+=1
                head=ptr
                ptr=ptr.next
            if ptr==None:
                return False
            else:
                return True      
```

![image.png](https://pic.leetcode-cn.com/d9f4646c6bb026b038b8e1427bc41bfa10cbfda1e1ca72baa48f8445c0abc80a-image.png)
