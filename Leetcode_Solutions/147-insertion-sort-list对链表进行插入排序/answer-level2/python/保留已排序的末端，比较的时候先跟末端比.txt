### 解题思路

思路 ？不存在的，我自己都绕晕了。

head 依次后移，每轮先跟已排好序的末端节点比，如果大于末端，直接接在后面，
如果小于末端，跟已排好的链表从头比，再插入

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        ret = ListNode(float('-inf'))
        cur = ret
        while head:
            if head.val > cur.val:
                cur.next = head
                cur = cur.next
                head = head.next
                cur.next = None
            else:
                pre = ret
                insertPos = pre.next
                while insertPos and insertPos.val < head.val:
                    insertPos = insertPos.next
                    pre = pre.next
                pre.next = head
                temp = head.next
                head.next = insertPos
                head = temp
        return ret.next
```