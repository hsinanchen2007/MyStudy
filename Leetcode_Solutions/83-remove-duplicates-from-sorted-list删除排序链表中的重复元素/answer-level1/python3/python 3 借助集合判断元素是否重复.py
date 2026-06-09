思路：借助一个nodeSet集合来保存未重复的值；使用cur节点和pre前驱节点，实现重复节点的删除。
首先nodeSet集合保存head的值。然后cur遍历head之后的节点，每次检查cur的值是否存在于集合中：
1.如果存在，则说明重复，那么pre.next = cur.next删除当前节点，并且cur=pre.next，继续遍历；
2.如果不存在，说明未重复，把值存到集合中，并且pre和cur都往后next一次。

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return None
        nodeSet = {head.val}
        pre = head
        cur = pre.next
        while(cur):
            if cur.val in nodeSet:
                pre.next = cur.next
                cur = pre.next
            else:
                nodeSet.add(cur.val)
                pre = cur
                cur = cur.next
        return head
```
