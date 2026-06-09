####  方法1：直接遍历（双指针）

|    时间复杂度     | 空间复杂度 |
| :---------------: | :--------: |
| O(n)，n为链表长度 |    O(l)    |

**基本思路：**

> 遍历链表，找到需要进行旋转的位置。

**代码：**

```python []
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return head

        # 获取链表长度
        p = head
        l = 0
        while p:
            l += 1
            p = p.next

        k = k % l  # k对l取余，避免重复循环导致的超时
        if k == 0:
            return head

        pre, post = head, head
        # 让一个指针先走k步
        for i in range(k):
            post = post.next

        # 两个指针一起走，直到后面的指针指向最后一个元素
        while post.next:
            pre = pre.next
            post = post.next

        # 将链表拆分之后再反转
        tmp = pre.next
        pre.next = None
        post.next = head

        return tmp
```