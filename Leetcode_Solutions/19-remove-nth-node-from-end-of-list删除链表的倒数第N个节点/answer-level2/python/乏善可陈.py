使用一个数组记录每个节点的指针，实现快速删除，注意边界条件。

整道题目的代码如下：

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        node_list = []
        num = 0
        res = head

        while(head is not None):
            node_list.append(head)
            head = head.next
            num = num + 1

        if num == 1:
            return None

        if num == n:
            return res.next

        temp_node = node_list[num - n - 1].next.next
        node_list[num - n - 1].next = temp_node

        return res
```

