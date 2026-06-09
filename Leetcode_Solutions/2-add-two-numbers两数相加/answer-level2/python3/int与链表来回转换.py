```python
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def ln_to_num(l:ListNode)-> int:
            a = 0
            res = 0
            while l:
                res = res + l.val*(10**a)
                a +=1
                l = l.next
            return res
        def num_to_ln(it:int) -> ListNode:
            res = ListNode(None)
            head = res
            while it//10 > 0:
                res.next = ListNode(it%10)
                it = it // 10
                res = res.next
            res.next = ListNode(it)
            return head.next
        l1_num = ln_to_num(l1)
        l2_num = ln_to_num(l2)
        return num_to_ln(l1_num+l2_num)
```
