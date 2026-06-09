一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路

方案1：

- 第一步：遍历老链表，构建正常的链表，用一个map记录p到new_p
- 第二步：新老链表同步next移动，对比记录random指针。

p        1->2->3->4
map      |  |  |  |
new_p    1->2->3->4

需要借助O(n)的空间，时间复杂度为o(n)

方案2：

不需要借助O(n)的空间，时间复杂度为o(n)

老新链表交叉存储，奇数位置为老链表，偶数位置新链表复制前一个位置。

新链表random即为旧链表random的后一个位置。

p1->p1'->p2->p2'->...->pn->pn'

### 代码

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, pHead):
        """
        :type head: Node
        :rtype: Node
        """
        if not pHead: return None
        p = pHead
        new_h = Node(p.val)
        pre_p = new_h
        random_map = {pHead: new_h}
        p = p.next
        while p:
            new_p = Node(p.val)
            random_map[p] = new_p
            pre_p.next = new_p
            pre_p = pre_p.next
            p = p.next
        p = pHead
        new_p = new_h
        while p:
            random_p = p.random
            if random_p:
                new_p.random = random_map[random_p]

            p = p.next
            new_p = new_p.next

        return new_h
```