### 解题思路
+ 迭代解法保存pre和cur就行，每次将cur.next = pre, 然后更新pre和cur
+ 递归解法中的递归函数的功能是每次反转head右侧的链表，并返回反转后的new_head,再将重新调整反转链表的尾部与当前head的连接

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 迭代解法
        pre,cur = None,head
        while cur:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp
        return pre
        
        # 递归解法
        if not head or not head.next:
            return head
        new_head = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return new_head
```