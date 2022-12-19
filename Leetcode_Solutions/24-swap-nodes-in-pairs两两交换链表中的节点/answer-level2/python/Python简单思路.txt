这题是[Reverse Nodes in k-Group](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/pythoncai-ji-ben-ban-fa-by-opencv/)在K=2的一个特例，所以解法通用。


- 把任务拆分成n/k组子序列，然后写一个helper方法，实现子序列内部翻转
- 注意上一步中需要暴露出3个变量：当前子序列的next，翻转后的head，和翻转后的tail
- 把不同子序列串起来。


```python
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        def helper(head):
            if not head or not head.next: return head, None, None
            p, q = head, head.next
            p.next = q.next
            q.next = p
            return q, p, p.next
        
        new_head, tail, nxt = helper(head)
        while nxt:
            _head, _tail, nxt = helper(nxt)
            tail.next = _head
            tail = _tail
        return new_head
```

因为不需要判断序列长度了，所以只需要遍历1遍。

时间：O(N)，空间：O(1)