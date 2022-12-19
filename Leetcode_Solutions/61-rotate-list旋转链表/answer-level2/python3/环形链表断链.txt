### 解题思路
解题思路：
1. 形成环
2. 找到新head
3. 断开环
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:           
        if head is None or head.next is None: return head
        
        # 连成环
        last = head
        count = 1
        while last.next is not None:
            last = last.next
            count += 1
        last.next = head
        
        # 步数换算
        step = (count - k) % count + 1
        slow = last
        fast = head
        
        # 寻找new head
        while step != 1:
            slow = slow.next
            fast = fast.next
            step -= 1
        slow.next = None
        
        return fast
```