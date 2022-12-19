一看到评论区的双指针恍然大悟
```
class Solution:
    def kthToLast(self, slow: ListNode, k: int) -> int:
        fast=slow

        while k:
            fast=fast.next
            k-=1

        while fast:
            slow=slow.next
            fast=fast.next

        return slow.val
```
