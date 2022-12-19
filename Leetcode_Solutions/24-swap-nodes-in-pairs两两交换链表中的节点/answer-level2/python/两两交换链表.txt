### 解题思路
将问题拆解成只有两个元素的链表。
首先，用back存储最初的头结点，然后令head为最新的头结点。
然后，用head作为遍历指针。当head存在时，查看是否存在head.next，进而查看是否有head.next.next。
如果都有，则可以继续下一次遍历。如果只有head.next或者没有，则说明遍历到头了。
每次遍历都修改指针即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
            return head
        ret, back = head.next, head
        head = head.next
        while head:
            cal, temp = None, None
            if head.next:
                temp = head.next
                if head.next.next:
                    cal = head.next.next
            head.next = back
            back = temp
            head = head.next
            if cal:
                head.next = cal
                head = head.next
            elif temp:
                head.next = temp
                break
            else:
                head.next = None
                break
        return ret

```