### 解题思路
1.双指针：已知n有效，则可以将指针先错开n-1位，之后不断滑动，直至右端抵达链表末端，左端指的就是要删除的节点
2.对节点进行讨论：删除头节点，删除中间节点（尾部节点）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 双指针：已知n有效，则可以将指针先错开n-1位， 之后不断滑动，直至右端抵达链表末端，左端指的就是要删除的节点
        # 对节点进行讨论：删除头节点，删除中间节点（尾部节点）
        t0, t1 = head, head
        for i in range(n-1):
            t1 = t1.next
        while t1.next:
            temp = t0
            t0 = t0.next
            t1 = t1.next
        if t0 == head:
            head = head.next
        else:
            temp.next = t0.next
        return head
```