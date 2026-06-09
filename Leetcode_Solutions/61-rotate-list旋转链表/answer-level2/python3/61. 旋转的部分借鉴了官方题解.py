### 解题思路
比较需要注意的是，闭环的操作要放到 k==0 的操作之后，要不然如果一旦出现k==0的情况，整个就是一个闭环状态了。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None or head.next is None:
            return head

        old_tail = head
        n = 1
        while old_tail.next:
            old_tail = old_tail.next
            n += 1

        k = k % n

        if k == 0:
            return head
        
        else:
            old_tail.next = head
            new_tail = head
            for i in range(n-k-1):
                new_tail = new_tail.next
            
            new_head = new_tail.next
            new_tail.next = None
            return new_head
            
```