```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        if head.next == None:
            return head
        pre = None
        cur = head
        ans = []
        n = 0
        while cur != None:
            n += 1
            ans.append(cur)
            cur = cur.next
        k = k % n
        while k:
            ans[-2].next = None
            ans[-1].next = ans[0]
            ans.insert(0,ans.pop())
            k -= 1
        return ans[0]
```
