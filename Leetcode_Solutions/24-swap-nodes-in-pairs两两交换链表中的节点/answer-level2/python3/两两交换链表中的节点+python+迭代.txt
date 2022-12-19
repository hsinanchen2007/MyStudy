####  方法1：迭代

| 时间复杂度 | 空间复杂度 |
| :--------: | :--------: |
|    O(n)    |    O(l)    |

**基本思路：**

> 如代码注释。

**代码：**

```python []
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        # 定义三个指针：pre、first、second，调换first和second的位置。
        # first.next, second.next = second.next, None
        # pre.next, second.next = second, first
        pre = ListNode(None)
        pre.next = head
        tmp = pre
        while pre.next and pre.next.next:
            first, second = pre.next, pre.next.next
            first.next, second.next = second.next, None
            pre.next, second.next = second, first
            pre = pre.next.next
        return tmp.next
```