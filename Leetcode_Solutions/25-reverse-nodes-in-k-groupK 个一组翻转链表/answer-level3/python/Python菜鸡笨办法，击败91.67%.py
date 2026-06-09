只写了一次肉眼目测没问题，直接提交竟然通过了。
![image.png](https://pic.leetcode-cn.com/9faba9475434a7eb966e1c638b30fbc12d8c083f8c4f497ab2002477935ba76f-image.png)

想法很简单，就是按照要求来硬做。

1. 把任务拆分成n/k组子序列，然后写一个helper方法，实现子序列内部翻转
2. 注意上一步中需要暴露出3个变量：当前子序列的next，翻转后的head，和翻转后的tail
3. 把不同子序列串起来。

```python
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        def helper(head, k):
            # 统计序列长度，如果小于k就直接返回原始序列
            length = 0
            _p = head
            while _p:
                length += 1
                _p = _p.next
            if length < k: return head, None, None
            if k <= 1: return head, None, None
            if not head or not head.next: return head, None, None

            # 老方法，每次拆解出一个，插入尾部。
            p = head
            cnt = 0
            new_head = None
            tail = new_head
            while p:
                q = p.next
                p.next = new_head
                new_head = p
                cnt += 1

                # 对第一次插入的特殊标记一下，因为它是tail
                if cnt == 1: tail = p
                if cnt == k: break
                p = q
            return new_head, q, tail

        q = head
        # 第一次翻转单独做，因为head会变成最终的head
        head, q, tail = helper(q, k)
        # 之后每次将上一次的tail跟这次的新head接上去就可以
        while q:
            _head, q, _tail = helper(q, k)
            tail.next = _head
            tail = _tail
        return head
```

## 复杂度分析
**时间复杂度**：
### O(2N)
因为q是跳跃的，所以只需遍历一遍list，然而每个子序列也需要遍历一次获得length，所以一共需要遍历2次。

**空间复杂度**：
### O(1)
