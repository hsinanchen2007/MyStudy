### 解题思路
递归方法

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
        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p
```

### 解题思路
非递归方法

### 代码

```python3
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        current = head
        while current != None:
            temp = current.next
            current.next = pre
            pre = current
            current = temp
        return pre
```


