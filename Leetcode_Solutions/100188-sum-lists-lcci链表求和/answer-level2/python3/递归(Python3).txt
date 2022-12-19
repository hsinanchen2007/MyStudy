### 解题思路
设置进位，逐步相加

### 代码

```python []
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        return self.addLists(l1, l2, 0)
    def addLists(self, l1, l2, carry):
        if not l1 and not l2 and carry == 0:
            return None
        value = carry
        if l1:
            value += l1.val
        if l2:
            value += l2.val
        result = ListNode(value % 10) # 数字的第二个数位
        if l1 or l2: # 递归
            more = self.addLists(l1.next if l1 else None, l2.next if l2 else None, 1 if value >= 10 else 0)
            result.next = more
        return result
```