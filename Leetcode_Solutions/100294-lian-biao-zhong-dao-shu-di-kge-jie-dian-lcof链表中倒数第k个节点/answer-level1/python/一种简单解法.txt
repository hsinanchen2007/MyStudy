一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路

用快慢指针，快指针比慢指针快k步，到尾结点了慢指针就是倒数第k个结点。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head: return None
        fast_p = head
        slow_p = head
        for _ in range(k):
            if fast_p:
                fast_p = fast_p.next
            else:
                return None
        while fast_p:
            fast_p = fast_p.next
            slow_p = slow_p.next
        return slow_p
```