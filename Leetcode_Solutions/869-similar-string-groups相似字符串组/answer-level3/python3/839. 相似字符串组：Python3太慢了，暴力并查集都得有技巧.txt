![image.png](https://pic.leetcode-cn.com/c5f31d4e05afc1df2c153cfd1c5f3dbcf6489c6558994ed4372b8f0a6229cb1d-image.png)


卡了两个星期终于AC，简单算法其他语言都能过，python这就过不了，这么个老题Python3的提交报告都生成不了柱状图，说明通过的人实在太少了。

这题出自[Weekly Contest 85/周赛85](https://leetcode-cn.com/contest/weekly-contest-85)，当时国内刚开始办周赛，这题国内只有两个人在比赛中用了非python的语言通过了，国际赛里面前30只有一个选手用python过了这题，他的算法是深搜，时间复杂度$O({N}^{2}M)$，放到现在也只能过30个数据这样。



国内其他语言通过一般都是暴力加并查集，但暴力也分两种暴力：

第一种是遍历字符串两两组合，然后比对字符串，如果不同的字符仅为2个，就用并查集把这两个串的所属集合连起来，时间复杂度为$O({N}^{2}M)$，其中$N$为串的数量，$M$为串的长度。

第二种是遍历每个字符串的两个位置生成通配串，然后存进数组匹配字典，如果两个串属于同一个通配串，就把两个串可以相连记录起来，最后遍历关系用并查集可得到答案，时间复杂度为$O(N{M}^{2})$。

其他语言大多用的是第一种算法，而python这种慢语言，单纯用任何一种都过不了，用第一种只能过$30$个数据左右，用第二种只能过$45$个数据左右，所以必须两者结合才能通过线上判定。

当$N$比较小的时候，选择前者，反之选择后者，最后都是并查集连接。

```python []
class Solution:
    def numSimilarGroups(self, A: List[str]) -> int:
        A = [*{*A}]                             #字符串去重，这个是题目给的坑
        n, m = len(A), len(A[0])
        self.p = [*range(n)]                    #并查集初始化
        self.nmm(A) if n > m * m else self.nnm(A)#选择方案
        return len({*map(self.uni, self.p)})    #并查集去重输出长度
    
    def uni(self, x: int):                      #并查集查询连接函数
        if x != self.p[x]:
            self.p[x] = self.uni(self.p[x])
        return self.p[x]
        
    def nnm(self, A: List[str]):                #O(N^2*M)算法
        n, m = len(A), len(A[0])
        def check(x, y):                        #相似判定函数
            t = 0
            for i in range(m):
                if x[i] != y[i]:
                    t += 1
                    if t > 2:
                        return False
            return True
        for i in range(n):
            for j in range(i + 1, n):           #遍历串的两两组合，然后并查集连接
                pi, pj = self.uni(i), self.uni(j)
                if pi != pj and check(A[i], A[j]):
                    self.p[pj] = pi
        
    def nmm(self, A: List[str]):                #O(N*M^2)算法
        n, m = len(A), len(A[0])
        d = collections.defaultdict(list)       #匹配字典
        e = set()                               #关系集合
        for i, w in enumerate(A):
            for l in range(m):
                for r in range(l + 1, m):       #遍历每个串的两个位置，生成通配串
                    t_w = f'{w[: l]}.{w[l + 1: r]}.{w[r + 1: ]}'
                    if d[t_w]:
                        for j in d[t_w]:        #生成串串关系
                            e |= {(i, j)}
                    d[t_w] += [i]
        for i, j in e:                          #遍历关系集合，然后并查集连接
            pi, pj = self.uni(i), self.uni(j)
            if pi != pi:
                self.p[pj] = pi
```
