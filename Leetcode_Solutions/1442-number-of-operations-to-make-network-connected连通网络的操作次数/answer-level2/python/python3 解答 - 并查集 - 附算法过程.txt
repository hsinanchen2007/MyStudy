### 解题思路
我使用并查集方法做，思路简单（我的博客中[并查集的题目列表](https://codeplot.top/tags/%E5%B9%B6%E6%9F%A5%E9%9B%86/)）

fa 数组存放每个节点的父亲，sz 存放每个节点树上的儿子大小。

通过查看树根的 sz ，可以知道当前的集合中有多少计算机，如果最大集合中的计算机数量等于 n，那么整个网络就联通了。

算法过程：

初始化并查集

初始化冗余网线数量 ：redundancy = 0
当前最大集合中计算机数： cur_max_net_size = 1
当前最大集合的树根： cur_max_net_fa = 0

首先遍历 connections。对于每一个连接，先看看，连接的两台计算机是否已经联通了：

如果没有就用并查集的 merge 操作合并两个计算机所在集合，并且获得集合中计算机数量，如果这个数量等于 n 了，就说明至此，网络就全联通了，直接返回 0 ，算法结束。
如果已经联通了，说明这个连接冗余了。这根网线就不用插了，直接把冗余网线数量加一
到这里没返回说明网络还没联通，这次遍历所有计算机，如果：

一台计算机已经属于当前最大网络了，不执行任何操作

一台计算机不属于当前最大网络，首先检查是否还有剩余网线（redundancy）：

如果没有剩余网线，说明无法完成任务，返回 -1
如果有剩余网线，把当前计算机 merge 到最大网络，操作数（result）加一，并查看最大网络计算机数是否是 n，如果是 n 接结束，返回当前操作数。

### 代码

```python3
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        fa = [i for i in range(n)]
        sz = [1 for i in range(n)]
        def getfa(x):
            if (fa[x] == x): return x
            fa[x] = getfa(fa[x])
            return fa[x]
        def merge(x, y):
            fx = getfa(x)
            fy = getfa(y)
            if fx == fy: return sz[fx], fx
            if sz[fx] > sz[fy]:
                fa[fy] = fx
                sz[fx] += sz[fy]
                return sz[fx], fx
            else:
                fa[fx] = fy
                sz[fy] += sz[fx]
                return sz[fy], fy
        redundancy = 0
        cur_max_net_size = 1
        cur_max_net_fa = 0
        for x, y in connections:
            fx = getfa(x)
            fy = getfa(y)
            if fx != fy:
                cur_size, cur_fa = merge(x, y)
                if cur_size > cur_max_net_size:
                    cur_max_net_size = cur_size
                    cur_max_net_fa = cur_fa
                if cur_size == n:
                    return 0
            else:
                redundancy += 1
        result = 0
        for i in range(n):
            fi = getfa(i)
            if fi != cur_max_net_fa:
                redundancy -= 1
                if redundancy < 0:
                    return -1
                result += 1
                cur_size, cur_fa = merge(i, cur_max_net_fa)
                if cur_size == n:
                    return result
```
[我的博客上的解答](https://codeplot.top/2020/01/12/leetcode-%E5%91%A8%E8%B5%9B-171-5309-%E8%BF%9E%E9%80%9A%E7%BD%91%E7%BB%9C%E7%9A%84%E6%93%8D%E4%BD%9C%E6%AC%A1%E6%95%B0-Number-of-Operations-to-Make-Network-Connected/)