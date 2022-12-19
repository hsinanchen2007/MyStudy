### 解题思路
这一题就是链表的位置转换，我算是钻空子了，没用使用数据结构的链表，而是把值都提取出来存到一个列表。
在两两转换的情况下，把列表两两分组，前后互换，如果有多的一个直接加在后面。

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        a = []
        while head:
            a.append(head.val)
            head = head.next
        if len(a) == 0:
            return
        index = list(range(1, len(a), 2))
        b = []
        for i in index:
            b.append(a[i])
            b.append(a[i-1])
        if len(a) % 2 != 0:
            b.append(a[-1])
        head = ListNode(None)
        p = ListNode(b[0])
        head.next = p
        for i in b[1:]:
            temp = ListNode(i)
            p.next = temp
            p = p.next
        return head.next
```