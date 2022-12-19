
- 我们使用快慢指针fast和slow
- 快指针先走k步，之后慢指针再开始走
- 这样快指针走到末尾的时候，slow正好走到倒数第k个

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        slow = fast = head

        while k != 0 and fast:
            fast = fast.next
            k -= 1
        while fast:
            fast = fast.next
            slow = slow.next
        return slow
        
```

**复杂度分析**

- 时间复杂度：我们遍历了一次全部节点， 因此时间复杂度为 $O(N)$ ， 其中N为节点个数。
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
