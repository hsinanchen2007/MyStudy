### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        """双指针的方法"""
        if not head:
            return
        head1 = head
        head2 = None

        i = 0
        while head1:
            head1 = head1.next
            if i >= n:
                if head2:
                    head2 = head2.next
                else:
                    head2 = head
            i += 1
        if head2:
            head2.next = head2.next.next
            return head
        return head.next

```