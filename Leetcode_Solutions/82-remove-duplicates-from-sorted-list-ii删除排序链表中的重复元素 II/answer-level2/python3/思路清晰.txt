### 解题思路

题不难，但是得注意边界
### 代码

```
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        pre = dummy
        while pre.next and pre.next.next:
            if pre.next.val == pre.next.next.val:
                temp = pre.next
                while temp and temp.next and temp.val==temp.next.val:
                    temp = temp.next
                pre.next = temp.next

            else:
                #pre 和 pre.next肯定不同
                pre = pre.next

        return dummy.next
```