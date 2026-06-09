### 解题思路
按照每 k 个节点翻转链表的思路写的，就是，每翻转 k 个节点，都得到 head, tail; 用 tail 指向下一次的head。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        res = head
        def swap(head):
            if head.next != None:
                next = head.next
                nnext = next.next
                next.next = head
                head.next = nnext
            else:
                return head
            return next
        
        first = True
        while head != None:
            # print('head',head.val)
            tail = head
            head = swap(head)
            if first:
                res = head
                lastTail = tail
                first = False
            else:
                lastTail.next = head
                lastTail = tail
            head = tail.next
            
        return res
```