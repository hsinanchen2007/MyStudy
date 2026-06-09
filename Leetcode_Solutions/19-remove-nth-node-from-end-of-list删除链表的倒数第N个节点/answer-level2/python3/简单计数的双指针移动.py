### 解题思路
双指针间隔n个节点同时向末尾移动, 待右侧指针到达末尾时，左侧指针正好指向要删除的节点
通过计数判断左侧指针何时移动，若未移动且差一步即将移动，说明n正好是链表长度，删除第
一个节点即可

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        prev = None
        curr = head
        count = 0
        while curr:
            curr = curr.next
            count += 1
            prev = head if count == n + 1 else prev
            if prev and count != n + 1:
                prev = prev.next
        if prev:
            prev.next = prev.next.next
        else:
            head = head.next if count == n else "n大于链表的长度"
        return head
```