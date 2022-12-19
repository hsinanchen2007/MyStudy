### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # 第一种方法递归，无需额外空间，超时
        # start = head
        # def helper(head):
        #     if head.next == None or head.next.next == None:
        #         return
        #     pre = cur = head
        #     while cur.next != None:
        #         pre = cur
        #         cur = cur.next
        #     node = head.next
        #     head.next = cur
        #     cur.next = node
        #     pre.next = None
        #     helper(node)
        # if not head or head.next == None:
        #     return head
        # helper(head)
        # return head

        # 第二种方法使用栈，速度较慢
        # if not head or head.next == None:
        #     return head
        # stack = []
        # cur = head
        # while cur:
        #     stack.append(cur)
        #     cur = cur.next
        # start = stack.pop(0)
        # while len(stack) > 1:
        #     start.next = stack.pop(-1)
        #     start.next.next = stack.pop(0)
        #     start = start.next.next
        # if not stack:
        #     start.next = None
        # else:
        #     start.next = stack.pop(0)
        #     start.next.next = None

        # 第三种使用栈，部分链表反转
        if not head or head.next == None:
            return head
        stack = []
        cur = head
        while cur:
            stack.append(cur)
            cur = cur.next
        n = len(stack)
        count = (n - 1) // 2
        p = head
        while count:
            tmp = stack.pop()
            tmp.next = p.next
            p.next  = tmp
            p = tmp.next
            count -= 1
        stack.pop().next = None



```