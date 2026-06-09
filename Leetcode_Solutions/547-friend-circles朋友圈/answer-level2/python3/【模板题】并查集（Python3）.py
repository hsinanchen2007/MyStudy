## 思路

并查集有一个功能是可以轻松计算出连通分量，然而本题的朋友圈的个数，本质上就是连通分量的个数，因此用并查集可以完美解决。

为了简单更加清晰，我将并查集模板代码单尽量独拿出来。

## 代码

find union connected 都是典型的模板代码。 懂的同学可能也发现了，我没有做路径压缩，这直接导致find union connected 的时间复杂度最差的情况退化到O(N)O(N)。

当然优化也不难，我们只需要给每一个顶层元素设置一个size用来表示连通分量的大小，这样union的时候我们将小的拼接到大的上即可。 另外find的时候我们甚至可以路径压缩，将树高限定到常数，这样时间复杂度可以降低到O(1)O(1)。

```python
class UF:
    parent = {}
    cnt = 0
    def __init__(self, M):
        n = len(M)
        for i in range(n):
            self.parent[i] = i
            self.cnt += 1
        
    def find(self, x):
        while x != self.parent[x]:
            x = self.parent[x]
        return x 
    def union(self, p, q):
        if self.connected(p, q): return
        self.parent[self.find(p)] = self.find(q)
        self.cnt -= 1
    def connected(self, p, q):
        return self.find(p) == self.find(q)

class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        n = len(M)
        uf = UF(M)
        for i in range(n):
            for j in range(i):
                if M[i][j] == 1:
                    uf.union(i, j)
        return uf.cnt
                    
```



**复杂度分析**

- 时间复杂度：平均 $O(logN)$，最坏的情况是 $O(N)$
- 空间复杂度：我们使用了 parent， 因此空间复杂度为 $O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)