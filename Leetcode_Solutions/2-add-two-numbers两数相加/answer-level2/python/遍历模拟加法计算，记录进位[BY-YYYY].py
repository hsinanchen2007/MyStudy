### 解题思路
>对两个链表同步进行遍历，按位模拟加法计算，记录进位，在下一位计算时考虑进位，不要忘记的是，遍历结束后如果有进位需要处理。性能一般。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        if not l2:
            return l1
        add = 0
        head, cur, last = None, None, None
        while l1 or l2:
            sum = (l1.val if l1 else 0) + (l2.val if l2 else 0) + add
            add = sum // 10
            cur = ListNode(sum % 10)
            if last:
                last.next = cur
            if not head:
                head = cur
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
            last = cur
        if add != 0:
            last.next = ListNode(add)
        return head
```

### 运行情况
执行用时 :76 ms, 在所有 Python3 提交中击败了54.42%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.41%的用户