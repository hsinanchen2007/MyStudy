### 解题思路
三个指针，分别标记要删除位置，要删除位置的前置，和距离删除位置 n 的位置。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        delete_pre = head
        index_delete = head
        index_tail = head
        i = 1
        while index_tail.next is not None:
            if i < n:
                i = i + 1
            else:
                if delete_pre == index_delete:
                    index_delete = index_delete.next
                else:
                    delete_pre = delete_pre.next
                    index_delete = index_delete.next
            index_tail = index_tail.next
        if i == n:
            if head != index_delete:
                delete_pre.next = index_delete.next
                index_delete.next = None
            else:
                head = head.next
                index_delete.next = None
        return head
```