### 解题思路
唯一需要考虑的就是提前构造一个`headhead`来准备head被删除的情况；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # count the length of list
        cur = head
        cnt = 0
        while cur:
            cur = cur.next
            cnt += 1
        cnt -= n
        # cut the target
        headhead = ListNode(0)
        headhead.next = head
        cur = head
        prev = headhead
        while cnt:
            prev = cur
            cur = cur.next
            cnt -= 1
        prev.next = cur.next
        return headhead.next
```