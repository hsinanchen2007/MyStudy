注意特殊情况吧，基本上没什么问题。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        back = head
        prior = head

        i = 0
        j = 0
        while i < j + n:
            back = back.next
            i += 1
        
        if back == None:
            return head.next

        # 找到倒数n个node的前一个指针
        while back.next != None:
            back = back.next
            prior = prior.next

        prior.next = prior.next.next

        return head
```