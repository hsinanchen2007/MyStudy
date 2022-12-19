```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    题目分析, 链表两两互换, 不能直接换值
    比如1->2->3->4, 变成2->1->4->3
    思路, 双指针p, q
    0->1->2->3->4, 两者指向变化如下:
    (捋不明白就拿临时变量全记下来)
    0, 2, p.next, p.next.next, p.next.next.next = q, p.next, q.next
"""
"""
    方法1, 双指针
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def pl(self, head: ListNode):
        while head:
            print(head.val, end=" ")
            head = head.next
        print("")

    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head

        ans = ListNode(-1)
        ans.next = head

        p, q = ans, head.next

        while True:
            # 全存了, 没必要为了简洁把脑子绕进去, -1->1->2->3
            x, y, z = p.next, q, q.next
            p.next, p.next.next, p.next.next.next = y, x, z

            # 这里终止条件要考虑奇数和偶数情况
            if not z or not z.next:
                return ans.next
            else:
                p, q = x, z.next

```
```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法2, 栈
"""
from collections import deque


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def pl(self, head: ListNode):
        while head:
            print(head.val, end=" ")
            head = head.next
        print("")

    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head

        ans, dq = ListNode(-1), deque()
        pos = ans

        dq.append(head)
        dq.append(head.next)
        head = head.next.next

        while dq:
            if len(dq) == 1:
                pos.next = dq.pop()
            else:

                pos.next = dq.pop()
                pos = pos.next
                pos.next = dq.pop()
                pos = pos.next

                # 这个地方是个大坑啊, 不加这个None输出ans的时候会一直循环
                pos.next = None

                if head:
                    dq.append(head)
                    head = head.next
                if head:
                    dq.append(head)
                    head = head.next

        return ans.next
```

```
# -*- coding: utf-8 -*-

# Author: Cynthia

"""
    方法3, 递归
    能用dequeue的好像也能用递归, 比如归并排序
"""


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def pl(self, head: ListNode):
        while head:
            print(head.val, end=" ")
            head = head.next
        print("")

    def swapPairs(self, head: ListNode) -> ListNode:
        def rf(h=head):
            if not h or not h.next: return h
            # 1->2->剩余
            x, y, z = h, h.next, h.next.next
            y.next, x.next = x, rf(z)
            return y

        return rf()

```


