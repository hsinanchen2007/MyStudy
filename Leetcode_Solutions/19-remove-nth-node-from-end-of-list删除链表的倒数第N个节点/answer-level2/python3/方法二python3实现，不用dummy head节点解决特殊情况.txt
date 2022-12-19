- **思路：**
找到倒数第n个节点的前一个节点，使该节点的next = 该节点的next.next
- **方法：**
双指针，fast先走n步，然后fast和slow一起走，直到fast到达终点。
- **特殊情况：**
如果要删除的节点是head，那么是不可能找得到head节点的前一个节点（因此看到有些题解设置了空的头结点，其实只要加一个判断就行了）

```python []
class Solution(object):
    def removeNthFromEnd(self, head, n):
        fast, slow = head, head
        # fast先走n步
        for _ in range(n):
            fast = fast.next
        # 特殊情况：可能一共只有n个节点，即删除头结点。此时fast一定是None
        if fast is None:
            head = head.next
            return head
        # 一起走到底，找到要删除的节点的前面一个节点
        while fast.next:
            fast, slow = fast.next, slow.next
        # 删除它
        slow.next = slow.next.next
        return head
```
