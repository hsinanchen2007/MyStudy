### 解题思路
核心思想：到两个结点的前缀和如果相等，则意味着两个结点之间的结点和为零。
两边遍历
第一遍 存储每个结点的前缀和，注意如果前缀和相等会覆盖掉上一个结点
第二遍 构造链表
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        seen = dict()
        profix = 0
        dummy = ListNode(0)
        dummy.next = head
        seen[0] = dummy
        while head:
            profix += head.val
            seen[profix] = head
            head = head.next

        head = dummy
        profix = 0

        while head:
            profix += head.val
            head.next = seen[profix].next
            head = head.next
        return dummy.next
```