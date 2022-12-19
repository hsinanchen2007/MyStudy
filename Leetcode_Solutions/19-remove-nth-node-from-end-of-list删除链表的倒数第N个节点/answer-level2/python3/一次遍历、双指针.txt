时间复杂度: O(1)
空间复杂度：O(1)
具体步骤：两个指针从头开始指向当前遍历的节点，第一个指针cur表示当前遍历到的节点，而第二个指针point每次向后试探n位，如果point指向了最后一个节点，则表示当前cur指向的节点就是要删除的节点。

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next == None:
            """判断是否只有一个元素，是就直接返回None"""
            return None
        cur = head
        point = head
        n1 = n
        while cur != None:
            while n1 != 0:
                point = point.next
                n1 -= 1
            if point == None:
                """
                特殊情况：这里说明头节点就是需要被去掉的，
                即n等于链表长度，直接返回
                """
                return head.next
            if point.next == None:
                cur.next = cur.next.next
                break
            cur = cur.next
            point = cur
            n1 = n
        return head
            
```
