![image.png](https://pic.leetcode-cn.com/1e22ad38133214e54f44c7fc33594c86d5375920ffdcd4efd701a311107224d4-image.png)


```
class Solution:

    def solve(self, head) -> bool:
        m = {}
        cur = head.next
        total = 0
        while cur:
            total += cur.val
            if total in m:
                m[total].next = cur.next
                return True

            if total == 0:
                head.next = cur.next
                return True

            m[total] = cur
            cur = cur.next

        return False

    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        fake = ListNode(0)
        fake.next = head

        while self.solve(fake):
            pass

        return fake.next
```
