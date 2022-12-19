### 解题思路
第一层依次减去一个平方数得到第二层，第二层依次减去一个平方数得到第三层，以此类推，直到某一层出现0或非零平方数。出现0则当前层数即为所求，出现非零平方数则当前层数+1为所求，有点提前终止搜索的意思

需注意，各节点先减去较大的平方数，再依次减去更小的平方数，直至减去1。如下图，n=15时，第一个节点依次减去9/4/1。利用队队列记录每个节点所减去的平方数和对应的差值，并逐层遍历队列元素。

对于第二层及更靠后层的节点，每个节点所减去的平方数，不超过与该节点相连的上层节点与该节点的差值。如第二层中数值为11的节点，它是由15减去4所得，所以它减去的平方不能大于，即它只依次减去4和1，不减9。从而达到剪枝目的，图中灰色节点即为待剪枝的节点。可在一定程度上，减少运行时间和存储占用。
![图片5.png](https://pic.leetcode-cn.com/6364924a50a159aad73a5dc7c92fb4a8e9d29145fb929f3bd0df848dde2d5f41-%E5%9B%BE%E7%89%875.png)


下图为剪枝后的情况
![图片7.png](https://pic.leetcode-cn.com/781ac0db6819b1e9fc22cbb95981e48b8a25f4525877c7689b7ade27538110d6-%E5%9B%BE%E7%89%877.png)


### 代码

```python3
class Solution:
    def numSquares(self, n):
        if n == 0: return 0
        level = 0
        queue = [(n, int(n**0.5))]
        while queue:
            level += 1
            length = len(queue)
            for _ in range(length):
                (tmp, k) = queue.pop(0)
                limit = min(int(tmp**0.5), k)
                for i in range(limit, 0, -1):
                    diff = tmp - i**2
                    if diff == 0:
                        return level
                    s = int(diff**0.5)
                    if s**2 == diff:
                        return level+1
                    queue.append((diff, i))
```