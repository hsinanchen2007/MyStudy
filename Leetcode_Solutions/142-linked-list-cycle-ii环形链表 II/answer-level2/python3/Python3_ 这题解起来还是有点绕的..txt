### 解题思路
参考一下别的评论写的.
首先是快指针f和慢指针s, 先找到相交点.
到了相交点以后, 再用一个p指针从head开始走和q指针从相交点开始走, 这两个指针相遇的地方就是环的入口.

写代码的时候注意有好几个地方要判断是不是空, 不然就会出bug.

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        f, s = head, head
        if f is None or s is None or f.next is None:  # 这里输入参数要先判断
            return None
        steps = 0
        flag = False
        while f.next and f.next.next and s.next:  # while的时候也要判断好f.next, f.next.next, s.next三个情况
            steps += 1
            f = f.next.next
            s = s.next
            if f == s:
                flag = True
                break
        if not flag:
            return None
        p = head
        q = s
        while True:
            if p == q:
                return p
            p = p.next
            q = q.next

```