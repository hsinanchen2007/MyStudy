### 解题思路
    原链表的最后一个节点指向了None，将原链表进行反转后，原链表中的第一个节点的next指向None，此时需要一个指针cur来控制循环，即当cur.next == None时，结束循环。
    在遍历的过程中，另外需要指针来保存前一个节点及后一个节点的位置，防止原链表的数据发生丢失。
    这里设定prev和nxt来分别保存前一个和后一个的节点位置。
    以列表[1,2,3,4]为例
    prev初始指向None，cur初始指向节点1的位置，
    pre = None
    cur = head
    在第一次的遍历中，nxt来指向cur后一个的节点位置，即节点2的位置，
    nxt = cur.next
    然后将cur此时所指的节点的next指向None,在每一次的反转过程中，cur此时所指节点的next都会指向其前一个节点prev
    cur.next = prev
    再将prev指向cur现在所指的位置,在下一次的循环中，prev依然相当于cur的前一个节点
    prev = cur
    最后更新cur的位置
    cur = nxt
### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        cur = head
        while cur != None:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt

        return prev
```