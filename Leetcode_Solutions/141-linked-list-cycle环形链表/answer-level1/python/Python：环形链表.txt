### 解题思路
说好的pos参数呢！
我写了半天，报错没有pos！！！！！
其实有了pos，也不好整，万一循环点不在pos，最后还得快慢指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        l=ListNode(0)
        l.next=head
        r=head
        while l!=r:
            if r and r.next:
                r=r.next.next 
            else:
                return False
            l=l.next
        return True
```