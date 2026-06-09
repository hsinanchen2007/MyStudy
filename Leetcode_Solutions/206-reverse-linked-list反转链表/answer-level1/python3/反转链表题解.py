### 解题思路
两种解法，迭代更优

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # 迭代法
    def reverseList1(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre

    # 递归法
    def reverseList2(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        end = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return end
```