内存为什么消耗那么高

执行用时  64 ms	 
内存消耗  13 MB


```
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 初始化
        p1, p2, carry = l1, l2, 0

        while p2 or carry:
            p2 = p2 if p2 else ListNode(0)

            count = p1.val + (p2.val if p2 else 0) + carry
            p1.val = (count - 10) if count >= 10 else count
            carry = 1 if count >= 10 else 0

            if not p1.next and (carry or p2.next):
                p1.next = ListNode(0)

            p1, p2 = p1.next, p2.next

        return l1
```