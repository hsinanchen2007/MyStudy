### 解题思路
借助dummy在最前面用于返回相当与res
建立pre，cur，post三个指针

然后原地调换，

```
# 设置两个新指针
cur = pre.next
post = pre.next.next
# 依次设置pre，cur，post的 next指针，pre和cur跳两步指，post指回cur
pre.next = post
cur.next = post.next
post.next = cur
# pre 跳两次
pre = pre.next.next
```

```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        # else:
        #     head, head.next, head.next.next = head.next, head, self.swapPairs(head.next.next)

        # return head
        
        dummy = ListNode(-1)
        dummy.next = head

        pre = dummy;
        while pre.next and pre.next.next:
            # 设置两个新指针
            cur = pre.next
            post = pre.next.next
            # 依次设置pre，cur，post的 next指针
            pre.next = post
            cur.next = post.next
            post.next = cur
            # pre 跳两次
            pre = pre.next.next

        return dummy.next
```

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        else:
            head, head.next, head.next.next = head.next, head, self.swapPairs(head.next.next)

        return head
```