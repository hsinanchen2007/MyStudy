思路是因为给的是一个`list`
就像直接用小根堆做,每次pop最小的`ListNode`,把他们连起来
然后push进`pop`出来的下一个节点到堆里面(节点不为空)
如此往复, 直到`list`为空

问题在于如果放进去的是`ListNode`
在heapify/pop/push过程中不支持比较操作
然后就试着用lambda函数付给了__lt__


```python
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        # 相当于 def __lt__(self, other)
        # 这里 x == self, y == other
        ListNode.__lt__ = lambda x, y: x.val < y.val
        # 防止有None在lists里导致heapify报错
        heap = [_ for _ in lists if _]
        dummy = ListNode(None)
        node = dummy
        # 构造小根堆
        heapq.heapify(heap)
        while heap:
            # 把pop出的结果和当前的链表最后一个节点连起来
            node.next = heapq.heappop(heap)
            node = node.next
            if node.next:
                heapq.heappush(heap, node.next)
        return dummy.next
```