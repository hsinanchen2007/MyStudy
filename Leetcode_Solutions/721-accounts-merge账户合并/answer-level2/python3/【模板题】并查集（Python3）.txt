
关于并查集的题目不少，官方给的数据是30道（截止2020-02-20），但是有一些题目虽然官方没有贴`并查集`标签，但是使用并查集来说确非常简单。这类题目如果掌握模板，那么刷这种题会非常快，并且犯错的概率会大大降低，这就是模板的好处。

我这里总结了几道并查集的题目：

- [990. 等式方程的可满足性](https://leetcode-cn.com/problems/satisfiability-of-equality-equations/solution/mo-ban-ti-bing-cha-ji-python3-by-fe-lucifer/)
- [547.朋友圈](https://leetcode-cn.com/problems/friend-circles/solution/mo-ban-ti-bing-cha-ji-python3-by-fe-lucifer-2/)

## 思路

我们抛开name不管。 我们只根据email建立并查集即可。这样一个连通分量中的email就是一个人，我们在用一个hashtable记录email和name的映射，将其输出即可。 

> 如果题目不要求我们输出name，我们自然根本不需要hashtable做映射

## 代码

find union connected 都是典型的模板代码。 然而我并没做计算连通分量，因此这道题根本不需要。 懂的同学可能也发现了，我没有做路径压缩，这直接导致find union connected 的时间复杂度最差的情况退化到O(N)O(N)。

当然优化也不难，我们只需要给每一个顶层元素设置一个size用来表示连通分量的大小，这样union的时候我们将小的拼接到大的上即可。 另外find的时候我们甚至可以路径压缩，将树高限定到常数，这样时间复杂度可以降低到O(1)O(1)。


```python
class UF:
    def __init__(self):
        self.parent = {}

    def find(self, x):
        self.parent.setdefault(x, x)
        while x != self.parent[x]:
            x = self.parent[x]
        return x 
    def union(self, p, q):
        self.parent[self.find(p)] = self.find(q)


class Solution:
    def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
        uf = UF()
        email_to_name = {}
        res = collections.defaultdict(list)
        for account in accounts:
            for i in range(1, len(account)):
                email_to_name[account[i]] = account[0]
                if i < len(account) - 1:uf.union(account[i], account[i + 1])
        for email in email_to_name:
            res[uf.find(email)].append(email)
        
        return [[email_to_name[value[0]]] + sorted(value) for value in res.values()]
```


**复杂度分析**

- 时间复杂度：平均 $O(logN)$，最坏的情况是 $O(N)$
- 空间复杂度：我们使用了 parent， 因此空间复杂度为 $O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)