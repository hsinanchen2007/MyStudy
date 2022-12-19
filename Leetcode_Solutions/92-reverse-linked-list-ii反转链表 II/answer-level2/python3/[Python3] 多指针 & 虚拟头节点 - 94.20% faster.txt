## 分析：

- 假设初始链表如(i)所示：
![IMG_20191201_121404.jpg](https://pic.leetcode-cn.com/7fec73c196b2cd10d8ba9cf5965b8332e77dceca081ff1025e04d4d4c9f4ff32-IMG_20191201_121404.jpg)

    (ii) 将m到n之间的指针翻转 (不包含第m个节点)
    (iii) 将第m个节点的next指针指向c所指节点，将a所指节点的next指针指向第n个节点

- 然后翻转链表：
![](https://pic.leetcode-cn.com/ed9d02f698591caa20d671b33c89ba2be53aa2d49962ff3470b3fa60753735a0.gif)

## 代码：
```python
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if m == n:
            return head
        dummy = ListNode(-1)
        dummy.next = head
        a, d = dummy, dummy
        for _ in range(m - 1):
            a = a.next
        for _ in range(n):
            d = d.next
        b, c = a.next, d.next
        pre = b
        cur = pre.next
        while cur != c:
            next = cur.next
            cur.next = pre
            pre = cur
            cur = next
        a.next = d
        b.next = c
        return dummy.next
```
