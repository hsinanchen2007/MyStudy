先添加一个空头，再交换
交换过程：
![a.jpg](https://pic.leetcode-cn.com/43254846f029b4814a6c9a139e4f9f89833ac54803ea50b24feb35210631f88b-a.jpg)

```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        thead = ListNode(-1)
        thead.next = head
        c = thead
        while c.next and c.next.next:
            a, b=c.next, c.next.next
            c.next, a.next = b, b.next
            b.next = a
            c = c.next.next
        return thead.next
```
