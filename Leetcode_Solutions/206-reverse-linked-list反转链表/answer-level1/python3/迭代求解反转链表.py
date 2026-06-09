### 解题思路
迭代嵌套求解

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        temp = head.next
        head.next = None
        reverseRest = self.reverseList(temp)
        temp.next = head
        return reverseRest
```