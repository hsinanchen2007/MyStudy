1. 双指针解法，让快指针先走k步，然后慢指针开始走，他们中间的距离就是k个节点
2. 快指针走到末尾时，慢指针真好走到倒数第k个节点
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        fast,slow = head,head
        for i in range(k):
            fast = fast.next
        while fast:
            fast = fast.next
            slow = slow.next
        return slow
```
