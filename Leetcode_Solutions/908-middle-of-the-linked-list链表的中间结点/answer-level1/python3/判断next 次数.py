### 解题思路
有没有人跟我思路一样：）

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        len = 1
        while True:
            if len == 1:
                next = head.next
            if next == None:
                break
            len += 1
            next = next.next
        midd = int(len /2)
        if midd == 0:
            return head
        for i in range(midd):
            if i ==0:
                next = head.next
            else:
                next = next.next
        return next
            

```