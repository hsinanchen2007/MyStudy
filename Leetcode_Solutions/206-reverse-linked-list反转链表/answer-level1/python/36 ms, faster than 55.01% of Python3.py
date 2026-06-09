### 解题思路
主要思想就是新建pre和next去保存当前节点的前一个和后一个结点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # if not head:
        #     return head
        # pre, head = head, head.next
        # pre.next = None
        pre = None
        while head:
            tmp = head.next
            head.next = pre
            pre, head = head, tmp
        return pre
```

递归
```
def reverseList(self, head: ListNode) -> ListNode:
        def solve(head, pre):
            if not head:
                return pre
            tmp = head.next
            head.next = pre
            return solve(tmp, head)
        return solve(head, None)
```

这个递归有意思
```
def reverseList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None: # 第一个判断条件只会用于初始的head就是None时
            return head
        
        p = self.reverseList(head.next) # 先遍历到底, 把最后一个元素拿到, 然后不断地向前传, 中间没有关于p的更改, 从而最后可以返回最后一个元素
        head.next.next = head
        head.next = None
        return p 
```