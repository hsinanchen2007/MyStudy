```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        pre, cur = None, head
        while cur:
            pre, cur = cur, cur.next
            while cur and pre.val == cur.val:
                pre.next, cur = cur.next, cur.next  
        return head

```
复杂度分析

时间复杂度：O(n)，因为列表中的每个结点都检查一次以确定它是否重复，所以总运行时间为 O(n)，其中 n 是列表中的结点数。

空间复杂度：O(1)，没有使用额外的空间。
