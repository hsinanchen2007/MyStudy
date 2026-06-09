**题目分析**
* 如果i到j的和为0 那么0-i和0-j的和应该是相等的
* 所以把前缘和用字典存储
* 遍历链表，如果当前的前缀和出现过，那么就移除这一段，继续递归下去

```python
class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        l = ListNode(0)
        l.next = head
        d = {0:l}
        s = 0
        while head:
            s+=head.val
            if s in d:
                d[s].next = head.next
                return self.removeZeroSumSublists(l.next)
            else:
                d[s] = head
                head = head.next
        return l.next
```

**复杂度分析**
* 时间复杂度 O(n) 最坏情况是 O($n^2$) 如 [2,2,2,-2,-2,-2]
* 空间复杂度 O(n) 最坏情况是 没有为0 的任何一段，那就要全部存储在字典中