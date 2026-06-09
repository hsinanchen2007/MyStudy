### 解题思路
快慢指针如果能相遇，说明存在环。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        if(head == None or head.next == None):
            return False
        node1 = head
        node2 = head.next
        while(node1 != node2):
            if(node2 == None or node2.next == None):
                return False
            node1 = node1.next
            node2 = node2.next.next
            
        return True
```