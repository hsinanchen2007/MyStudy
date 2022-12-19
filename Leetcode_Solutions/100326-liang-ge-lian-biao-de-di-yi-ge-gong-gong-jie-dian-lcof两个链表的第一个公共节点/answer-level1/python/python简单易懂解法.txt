一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 关注交流。

### 解题思路
倒序看，p1和p2两个链表的第一个公共结点到尾结点的长度一定相同。因此我们先对齐两个链表，再一起往后走找到第一个公共结点即可。

- 1. 找出两个链表长度，n1和n2，长的链表先走n1-n2步。
- 2. 一起往后走，找到第一个公共结点。

### 代码

```python
class Solution(object):
    def getIntersectionNode(self, pHead1, pHead2):
        p1, n_p1 = pHead1, 0
        p2, n_p2 = pHead2, 0
        while p1:
            p1 = p1.next
            n_p1 += 1
        while p2:
            p2 = p2.next
            n_p2 += 1
        if n_p1 < n_p2:     # p1指向长链
            pHead1, pHead2 = pHead2, pHead1
            n_p1, n_p2 = n_p2, n_p1

        for _ in range(n_p1 - n_p2):
            pHead1 = pHead1.next
        while pHead1 and pHead2:
            if pHead1 == pHead2:
                return pHead1
            else:
                pHead1 = pHead1.next
                pHead2 = pHead2.next
        return None
```