基础不牢地动山摇，比赛的时候就这题没做出来，图的最小生成树，确实属于基础题。

![image.png](https://pic.leetcode-cn.com/a71ad6aba3de2aec2cdde03e8f7717998c6b287909dd83d51ad5a79071b1a316-image.png)

```
class Solution:
    def minimumCost(self, N: int, connections: List[List[int]]) -> int:
        p = [i for i in range(N + 1)]       #并查集初始化
        connections.sort(key = lambda x: x[2])      #按边的长度升序排序，贪心初始化
        
        def f(x):       #查找修改所属集合
            if p[x] != x:
                p[x] = f(p[x])
            return p[x]

        count = 0
        ans = 0
        for x, y, c in connections:
            px, py = f(x), f(y)
            if px != py:        #属于不同集合的时候，累加值里添加上边的长度，并且合并集合
                count += 1
                ans += c
                if count == N - 1:      #添加了足够的点，就返回
                    return ans
                p[px] = py

        return -1
```
