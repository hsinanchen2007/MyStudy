依照 java 版写的，测试通过，结构清晰易读。

```python
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummyHead = ListNode(0)
        p = l1
        q = l2
        curr = dummyHead

        carry = 0

        while p or q:
            x = p.val if p else 0
            y = q.val if q else 0

            sum = x + y + carry
            carry = sum / 10
            curr.next = ListNode(sum % 10)

            curr = curr.next

            if p:
                p = p.next

            if q:
                q = q.next

        if carry > 0:
            curr.next = ListNode(carry)

        return dummyHead.next
```