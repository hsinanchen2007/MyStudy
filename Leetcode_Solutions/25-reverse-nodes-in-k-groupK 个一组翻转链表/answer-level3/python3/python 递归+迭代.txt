### 解题思路
如果知道 k 个一组的链表翻转结果 head,tail,就容易完成递归；tail.next 为下一组k个链表的表头。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def helper(self, head, N, k):
        if (N < k) or (head == None):
            return head,None

        dummy = ListNode(-1)
        dummy.next = head
        for _ in range(k-1):
            next = head.next
            head.next = next.next
            next.next = dummy.next
            dummy.next = next
        tail = head
        head = dummy.next

        _head, _tail = self.helper(tail.next, N-k, k)
        tail.next = _head
        return head,tail

    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        cnt = 0
        t = head
        while t != None:
            cnt += 1
            t = t.next
        h, t = self.helper(head, cnt, k)
        return h


```