### 解题思路
1. 直接法：直接判断值是否相等，相等的话直接下一个
2. 递归判断下一个子节点的值是否相等，不等的话下一个

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        # dummy_head = ListNode(None)
        # dummy_head.next = head

        # pre = dummy_head
        # cur = head

        # while cur:
        #     if pre and cur.val == pre.val:
        #         pre.next = cur.next
        #         cur.next = None
        #         cur = pre.next
        #         continue

        #     pre = cur
        #     cur = cur.next
        # return dummy_head.next

        # if head is None or head.next is None:
        #     return head
        
        # child = self.deleteDuplicates(head.next)
        # if child and child.val == head.val:
        #     head.next = child.next
        #     child.next = None
        # return head

        current = head
        while current is not None and current.next is not None:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next
        return head
```