语言；Python3
效果：O(n) 56ms 14MB
```python []
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        # 一个元素直接返回
        if not head.next:
            return head
        # m,n相同直接返回
        if m == n:
            return head
        cur, pre = head, None
        # 找到反转起始节点的前置节点和反转的终止节点
        for i in range(m - 1):
            cur, pre = cur.next, cur
        start, end = pre, cur
        # 按照次数实施反转
        pre = None
        for i in range(0, n - m + 1):
            cur.next, pre, cur = pre, cur, cur.next
        # 结束节点连接
        end.next = cur
        # 起始节点连接
        if m != 1:
            start.next = pre
            return head
        else:
            return pre
```
