# 1. 思路：

# 1.1 题目分析：

首先吐槽一下题目，我左看右看也没看懂-_-||

题目含义是：如果想移除一个石头，那么它所在的行或者列必须有其他石头存在。我们能移除的最多石头数是多少？

也就是说，**只有一个石头在连通分量中，才能被移除**。对于连通分量而言，最理想的状态是只剩一块石头。**对于任何容量为n一个连通分量，可以移除的石头数都为n-1**。

那么问题就被转化为：

**这些石头可以构成多少个连通分量，每个分量中有多少块石头？**

进一步地，由于题目中强调了，每个坐标点最多只能有一块石头，也就是说给定的stones列表中没有重复坐标，总石头数等于stones列表的长度。而每个连通分量最后都会剩下一块石头，所以：

**可以移走的石头数 = 总石头数 - 剩余石头数 = stones列表长度 - 连通分量个数**

# 1.2 连通分量计算：

事实上，连通分量计算最好的办法是并查集，可是我们这里偏要勉强，用DFS解法计算（实际上是渣渣并不懂并查集￣□￣｜｜）。

值得注意的是，连通的条件是：**两个点在同一行或者同一列**，为了保存行和列信息，我们用两个set进行记录，即row和col。剩余部分与其他连通分量计算的题大同小异，详见代码。

# 2. 代码：

```
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        m = 0                                    # 记录最大的行坐标
        row = collections.defaultdict(set)       # 记录每一行中点的列坐标
        col = collections.defaultdict(set)       # 记录每一列中点的行坐标

        for i,j in stones:                       # 遍历所有石头坐标
            row[i] |= {j}                        # 记录行对应的列坐标
            col[j] |= {i}                        # 记录列对应的坐标
            m = max(m,i)                         # 记录最大的行坐标


        graph = 0                                # 连通分量的个数

        for i in range(m+1):                     # 对于所有的i进行遍历
            if i in row:                         # 如果i在row中，即i对一个新的连通分量
                graph += 1                       # 连通分量数 +1
                stack = {i}                      # 这里用set模拟栈，方便后面合并操作

                while stack:                     # 栈非空时
                    x = stack.pop()              # 从栈中不断弹出行坐标x
                    for j in row[x]:             # 对于row[x]中所保存的所有列坐标j
                        if j in col:             # 如果col[j]非空，说明该列有对应的行
                                                 # 可以和当前行x构成连通分量
                            stack |= col[j]      # 将col[j]中所有的行合并到栈中
                            del col[j]           # 并删除col[j]，防止循环调用
                    
                    del row[x]                   # 最后删除row[x]，防止循环调用

        return len(stones) - graph               # 针对于每个连通分量，最后只剩一个石子
                                                 # 因此剩余石子个数为连通分量个数graph
                                                 # 由于石子坐标是唯一的
                                                 # 因此总石子个数为stones的长度
                                                 # 可操作数为总石子数 - 剩余石子数
                                                 # 即 len(stones) - graph

```

![68ms.png](https://pic.leetcode-cn.com/9d9029c74f8e3f1022bfc229edc6fddb43d6439cdf8ec667e2ca05ccf3fed62c-68ms.png)
