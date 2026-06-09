### 解题思路
递归

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # def reverseList(self, head: ListNode) -> ListNode:
    def reverseList(self, head):
        # if head == None or head.next == None:
        #     return head

        # pre, cur = None, head
        # while cur:
        #     # change the point direction and update the pre/cur position
        #     cur.next, pre, cur = pre, cur, cur.next
        # return pre
        # 递归
        if not head or not head.next:
            return head
        nextNode = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return nextNode
```