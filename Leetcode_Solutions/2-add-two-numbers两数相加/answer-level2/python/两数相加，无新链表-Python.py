**两数相加-Python**

`思路`

 - 个位相加，遇10进1
 - 同步修改两个链表相同位置的值
 - 将最长的列表返回

主要特点：不需要新建链表

```python
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        self.head = l1
        self.pre = None
        addend = l1
        augend = l2
        divisor = 0
        while addend or augend:
            l1a = 0 if addend is None else addend.val
            l2b = 0 if augend is None else augend.val
            sum = l1a + l2b + divisor
            divisor = sum / 10
            remainder = sum % 10
            if addend is not None:
                addend.val = remainder
                self.pre = addend
                addend = addend.next
                self.head = l1
            if augend is not None:
                augend.val = remainder
                self.pre = augend
                augend = augend.next
                self.head = l2
        if divisor == 1:
           self.pre.next = ListNode(divisor)
        return self.head
```