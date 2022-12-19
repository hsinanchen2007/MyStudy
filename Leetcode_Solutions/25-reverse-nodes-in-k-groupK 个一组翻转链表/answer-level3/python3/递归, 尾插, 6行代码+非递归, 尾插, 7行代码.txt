递归
```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        if not head: return head

        ans, h, c = ListNode(-1), head, 1

        while h and c <= k: h.next, ans.next, h, c = ans.next, h, h.next, c + 1

        if c > k: head.next = self.reverseKGroup(h, k)
        else: ans.next = self.reverseKGroup(ans.next, c - 1)

        return ans.next
```
非递归
```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:

        pos = ans = ListNode(-1)

        while True:
            h, c = head, 1
            if not h: return ans.next

            while h and c <= k: h.next, pos.next, h, c = pos.next, h, h.next, c+1

            if c > k: head.next, pos, head = h, head, h
            else: head.next, head, k = None, pos.next, c-1
```
