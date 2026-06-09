### 解题思路
利用Python的多元赋值，等号两侧的值会分别用一个元组存起来，再按从左到右的顺序依次赋值。
例如：`x, y = y, x`, 运行时首先构造一个元组`(y,x)`，再构造另一个元组`(x,y)`，然后从左到右依次把`(y,x)`中的值赋值给`(x,y)`

实现链表反转，需用一个指针`pre`记录已经反转后的链表头，用另一个指针`post`表示还未进行反转的链表头.
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        pre, post = None, head
        while post:
            pre, pre.next, post = post, pre, post.next
        return pre

        # # def rev(head, rever):
        # #     if not head:
        # #         return rever
        # #     post = head
        # #     head = head.next
        # #     post.next = rever
        # #     return rev(head, post)
        # # return rev(head, None)
```