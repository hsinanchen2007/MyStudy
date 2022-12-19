

关于并查集的题目不少，官方给的数据是30道（截止2020-02-20），但是有一些题目虽然官方没有贴`并查集`标签，但是使用并查集来说确非常简单。这类题目如果掌握模板，那么刷这种题会非常快，并且犯错的概率会大大降低，这就是模板的好处。

我这里总结了几道并查集的题目：

- [547.朋友圈](https://leetcode-cn.com/problems/friend-circles/solution/mo-ban-ti-bing-cha-ji-python3-by-fe-lucifer-2/)
- [721. 账户合并](https://leetcode-cn.com/problems/accounts-merge/solution/mo-ban-ti-bing-cha-ji-python3-by-fe-lucifer-3/)

## 思路

并查集有一个重要的特征就是传导性，即A和B是连通的，B和C是连通的，那么A和C就是连通的。 是不是感觉和题目有点像？

题目中的 == 也一样具体传导性，因此我们的想法是基于 == 去 union 两个元素。 如果两个元素是连通的，并且 equation是 != 那么我们返回False，其他情况返回True

为了简单更加清晰，我将并查集模板代码单尽量独拿出来。


## 代码

find union connected 都是典型的模板代码。 然而我并没做计算连通分量，因此这道题根本不需要。 懂的同学可能也发现了，我没有做路径压缩，这直接导致find union connected 的时间复杂度最差的情况退化到$O(N)$。

当然优化也不难，我们只需要给每一个顶层元素设置一个size用来表示连通分量的大小，这样union的时候我们将小的拼接到大的上即可。 另外find的时候我们甚至可以路径压缩，将树高限定到常数，这样时间复杂度可以降低到$O(1)$。


```python
class UF:
    parent = {}
    def __init__(self, equations):
        for eq in equations:
            self.parent[eq[0]] = eq[0]
            self.parent[eq[3]] = eq[3]
        
    def find(self, x):
        while x != self.parent[x]:
            x = self.parent[x]
        return x 
    def union(self, p, q):
        if self.connected(p, q): return
        self.parent[self.find(p)] = self.find(q)
    def connected(self, p, q):
        return self.find(p) == self.find(q)



class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UF(equations)
        for eq in equations:
            if eq[1] == '=':
                uf.union(eq[0], eq[3])
        for eq in equations:
            if eq[1] == '!' and uf.connected(eq[0], eq[3]):
                return False
        return True

        
```
**复杂度分析**
- 时间复杂度：平均 $O(logN)$，最坏的情况是 O(N)$
- 空间复杂度：我们使用了 parent， 因此空间复杂度为 $O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)