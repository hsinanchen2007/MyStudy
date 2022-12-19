二分偷懒使用了python自带的二分库来做，也可以自己实现，时间复杂度O(nlogk)
```python
from bisect import bisect

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        _sorted = sorted([(l.val, l) for l in lists if l], key=lambda x: x[0])  # 先按头节点排序
        dumb = p = ListNode(0)
        while _sorted:
            val, node = _sorted.pop(0)  # 每次取出最小节点
            p.next = node  # 插入到当前位置
            p, node = p.next, node.next
            if node:  # 所取出的节点若还有后续，把它二分插入排序好的列表
                _sorted.insert(bisect([v[0] for v in _sorted], node.val), (node.val, node))
        return dumb.next
```
