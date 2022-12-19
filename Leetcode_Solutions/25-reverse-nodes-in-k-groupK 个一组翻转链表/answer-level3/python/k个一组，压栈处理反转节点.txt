```
def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        from collections import deque

        if k < 2:
            return head
        node_deque = deque()
        pre = ListNode(-1)
        pre.next = head
        x = pre
        count = k

        while x is not None:
            c = x
            while count > 0 and c is not None:
                c = c.next
                count -= 1
                node_deque.append(c)
            if count != 0 or c is None:
                return pre.next
            # c为反转节点
            c = node_deque.pop()
            z = c.next   # 保存后继

            if pre.next == head:    # 表头处理
                pre.next = c
            else:       # 前驱-->反转节点
                x.next = c
            # 反转前k个节点
            while node_deque:
                y = node_deque.pop()
                c.next = y
                c = y
            # 下一组循环
            x = c   # 作为下一组前驱
            x.next = z
            count = k

        return pre.next
```
