使用字典来存储链表每个节点的地址值 同时计数，然后删除要求的节点。空间换时间

```
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        curr = head
        i = 1
        listnode_dict = {}

        while curr is not None:
            listnode_dict[i] = curr
            curr = curr.next
            i += 1
        # i会比链表长度大1，所以下面都要减去
        if i-1-n == 0:
            head = head.next
        else:
            listnode_dict[i-1-n].next = listnode_dict[i-n].next

        return head
```
