### 解题思路
get_num 把 ListNode 转为 int
make_list 把数字转为 ListNode（但是不能处理 0）

### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        def get_num(l):
            if not l: return 0
            return l.val + get_num(l.next) * 10
        def make_list(n):
            if n == 0: return None
            l = ListNode(n%10)
            l.next = make_list(n//10)
            return l
        s = get_num(l1) + get_num(l2)
        if s == 0:
            return l1
        return make_list(s)
```