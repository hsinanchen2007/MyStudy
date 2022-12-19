可以建立一个小顶堆，将这些列表放入，每次从其中取值即可。

整道题目的代码如下：

```python
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        from Queue import PriorityQueue

        head = point = ListNode(0)
        q = PriorityQueue()

        # initialize heap
        for l in lists:
            if l:
                q.put((l.val, l))

        while not q.empty():
            val, node = q.get()
            node = node.next
            point.next = ListNode(val)
            point = point.next
            if node:
                q.put((node.val, node))

        return head.next
```

