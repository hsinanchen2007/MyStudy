### 解题思路

建一个临时头结点，按顺序比较相邻的两个节点的大小，若不同，将当前节点放到临时节点尾部，将指针挪到当前节点的下一个节点。若相同，直接将指针挪到当前节点的下一个节点，顺便将f改为false。为的是避免连续出现多个不同的相同值时（a,a,a,b,b,b,c,c,c）比较的第三个a，第一个b的情况。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        temp = ListNode(0)
        node = temp
        cur = head
        f = True
        while cur:
            if cur.next:
                if cur.val != cur.next.val:
                    if f:
                        temp.next = cur
                        temp = temp.next
                    cur = cur.next
                    f = True
                elif cur.next:
                    f = False
                    cur = cur.next
            else:
                if f:
                    temp.next = cur
                else:
                    temp.next = None
                cur = None
        return node.next

```