首先理清题意，在本题中，链表的val同时也是链表的id，所以是唯一的。

想象一下，**如果这道题没有随机指针，怎么做呢？**

很简单，创建一个新的 Node, 用一个指针指向老链表，不断向后移动元素；新链表直接跟着一路 new 过去，每次 new 的时候 val 复制原 val, next 指向我们自己 new 出来的 node 就可以了。就像下图一样：

![未标题-3.png](https://pic.leetcode-cn.com/f8064c7f58d5c36a8f9999d344502faf6906d91b98a82a3d131d763e863a4203-%E6%9C%AA%E6%A0%87%E9%A2%98-3.png)



但如果按照这个思路处理 random 指针，会发现一个问题：**我们在给 random 指针赋值的时候，不知道它应该指向哪里。**

指向 next 吗？显然太搞笑了。

指向原指针的 random 吗？不，那样指向的是老链表的节点，我们要的是指向新链表的节点。例如下图，如果老链表某个节点的 random 指向了老链表中`id=4`的节点，那新链表的对应节点的 random 也要指向新链表中的 `id=4` 的那个节点。可是，新节点很可能还没有被复制出来，怎么指向啊？

![未标题-31.png](https://pic.leetcode-cn.com/62ee607c61fd9aaff535286d31f888329321d8b215c6f5af455d3e37323b4517-%E6%9C%AA%E6%A0%87%E9%A2%98-31.png)


我们自然会想到，可以先把这种无头指针的情况记录下来，等所有节点都复制完了，再逐个进行指向操作。我们可以用一个元组`(无头random指针所在的节点id，random应该指向的节点id)`来记录。如果一个新复制的节点的 random 指向了一个已经复制的指针，那就在复制的时候直接给它指过去。

**这样核心思路就已经确定下来了。**

但是我们面临一个新的问题，想必聪明的朋友一定已经看出来了。众所周知，链表的读取不是 $O(1)$，最坏可以达到 $O(n)$，如果我们的运气不佳，遇到了下图这样丧心病狂的一个链表：

![未标题-4.png](https://pic.leetcode-cn.com/aef1271bfaee5eccfd2c079d0feed1ac564edb372a0a7767cddf7936f5d18b4d-%E6%9C%AA%E6%A0%87%E9%A2%98-4.png)


这尼玛读取的时间复杂度直接就是线性级别 $O(n)$ 的了，想到我们在复制的时候肯定是对每一个节点都进行操作，总体上还要乘个 $n$，这总体时间复杂度直逼 $O(n^2)$，不可接受啊！！！
所以我们要降低时间复杂度。一个个 new 过去的 $O(n)$ 是不可避免的，但是读取的时间复杂度可以给他降成 $O(1)$。没错，让我们请出这一有力工具——**散列表**。
前面已经说过，链表的 val 是唯一的。我们在每次 new 新节点的时候，不妨在 Hash 表里存储它，用 val 做**键**，而**值**就是指向这个新节点的指针。**那么我们用 id 找节点的操作就是 $O(1)$ 的了。**

下面给出这个完整题解

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':

        memo = {} # Hash表用字典实现
        random_unpointed_news = [] # 记录未处理 random 指针的节点信息

        # 下面两个节点是旧链表和新链表的伪头，用伪头写循环更方便
        old = Node(None, head, None)
        start = new = Node(None, None, None)

        while old.next is not None:
            old = old.next
            new.next = Node(old.val, old.next, None)
            new = new.next
            memo[new.val] = new # 记录所有已被复制的id所对应的节点指针，以使新链表存取效率达到O(1)
            if old.random is not None:
                if old.random.val in memo: # 如果随机指针指向的节点已被复制
                    new.random = memo[old.random.val] # 直接指向过去
                else: #随机指针指向的节点尚未被复制
                    random_unpointed_news.append((new.val, old.random.val)) # 把这个节点id和这个节点的random指针要被指向的节点id记录下来
        # 复制完成后，处理未完成的 random 指针
        for node_id, random_point_to_id in random_unpointed_news:
            memo[node_id].random = memo[random_point_to_id]

        return start.next # 注意 start 是伪头，其 next 节点是真正的头部
```
