### 解题思路

    递归法 就是前一个反转为后一个就可

### 代码

```python3


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None

        pre = None
        cur = head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre

    def reverseList_re(self, head: ListNode) -> ListNode:
        # 使用递归翻转
        if not head:
            return None
        pre = None
        self.res = None
        self.re(pre, head)
        return self.res

    def re(self, pre: ListNode, cur: ListNode):
        # 翻转以
        if cur is None:
            self.res = pre
            return
            # 先写基本的逻辑
        tmp = cur.next
        cur.next = pre
        self.re(cur, tmp)
```