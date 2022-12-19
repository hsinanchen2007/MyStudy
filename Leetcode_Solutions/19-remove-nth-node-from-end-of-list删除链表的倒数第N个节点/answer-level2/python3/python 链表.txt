### 解题思路
要注意h = head中间的h相当于C++中的移动指针

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
    #     h = head
    #     LEN = head
    #     form = ding = head
    #     p=dummy=ListNode(-1)
    #     q = dd=ListNode(-1)

    #     length = 0
    #     while LEN:
    #         length += 1
    #         LEN = LEN.next

    #     i = 0
    #     while h:
    #         i+=1
    #         if i==length-n+1:
    #             p.next=h.next
    #             break
    #         else:
    #             h=h.next

    #     i = 0
    #     while form:
    #         i+=1
    #         if i==length-n:
    #             form.next=None
    #             break
    #         else:
    #             form = form.next
    #     print(ding,'\n',p.next)
    #     cur = ding
    #     while cur.next is not None:
    #         cur = cur.next
    #     cur.next = p.next

    #     return ding

    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(-1)
        dummy.next = head
        fast = slow = dummy

        while n and fast:
            fast = fast.next
            n -= 1
        
        while fast.next and slow.next:
            fast = fast.next
            slow = slow.next
            
        slow.next = slow.next.next
        return dummy.next
```