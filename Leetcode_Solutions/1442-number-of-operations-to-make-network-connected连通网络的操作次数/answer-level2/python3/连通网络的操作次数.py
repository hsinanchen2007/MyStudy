#### 分析

本题的方法基于特定的结论。在介绍方法之前，我们先对题目进行一些分析。

我们首先考虑在什么情况下，不可能将所有计算机进行连接。当计算机的数量为 `n` 时，我们至少需要 `n - 1` 根线缆才能将它们进行连接。一种简单的方法是，将编号为 `0` 的计算机依次连接到编号为 `1, 2, ..., n - 1` 的计算机。如果线缆的数量少于 `n - 1`，那么我们无论怎么使用线缆，都无法将这 `n` 台计算机进行连接。因此如果数组 `connections` 的长度小于 `n - 1`，我们可以直接返回 `-1`；而当数组 `connections` 的长度大于等于 `n - 1` 时，我们一定可以找到一种修改线缆的方式。

那么如何计算最少的操作次数呢？我们将这 `n` 台计算机看成 `n` 个节点，每一条线缆看成一条边，那么计算机和线缆就组成了一个无向图。假设这个无向图中有 `k` 个连通分量，连通分量的定义为：

> 设集合 `S` 为无向图中节点的一个子集。`S` 为无向图的一个连通分量，当且仅当 `S` 中的节点两两可达，并且不存在一个不属于 `S` 的节点 `x`，使得 `x` 可以到达 `S` 中的所有节点。

> 在题目给出的样例 1 中，有两个连通分量 `{0, 1, 2}` 和 `{3}`；在题目给出的样例 2 中，有三个连通分量 `{0, 1, 2, 3}`、`{4}` 和 `{5}`。

如果我们的操作是「添加一根线缆」而不是「移动一根线缆」，那么我们只需要添加 `k - 1` 根线缆就可以将所有计算机进行连接了，一种简单的方法是，将编号为 `0` 的连通分量中的任意一台计算机与编号为 `1, 2, ..., n - 1` 的连通分量中的任意一台计算机相连。考虑到「移动一根线缆」的操作一定不会优于「添加一根线缆」，那么我们至少需要移动 `k - 1` 根线缆，才有可能将所有计算机进行连接。

我们是否可以找到一种移动 `k - 1` 根线缆的操作方法呢？通过之前的分析，我们可以发现，对于 `m` 台电脑，我们只需要 `m - 1` 根线缆就可以将它们进行连接。如果一个节点数为 `m` 的连通分量中有超过 `m - 1` 条边，就一定可以找到一条多余的边，且移除这条边之后，连通性保持不变。我们就可以用这条边来将连接两个连通分量，使得图中连通分量的个数减少 `1`。

> 在题目给出的样例 2 中，连通分量 `{0, 1, 2, 3}` 中有 `5` 条边，大于 `m - 1 = 3`，因此一定可以找到一条多余的边。具体地，该连通分量中的任意一条边被移除后，连通性都保持不变。注意：并不是在所有的情况下，连通分量中的任意一条边都是可以被移除的，我们只需要保证找到「一条」多余的边。

因此我们可以找出多余的边，连接图中的连通分量，最终使得整个图连通。我们断定，如果图中有 `k` 个连通分量且 `k > 1`（即整个图还没有连通），那么一定存在一个连通分量有一条多余的边，即它的节点数为 `mi`，边数为 `ei`，并且有 `ei > mi - 1`。

我们可以使用反证法证明这个结论：假设所有的连通分量都满足 `ei <= mi - 1`，那么有：

$$
\begin{aligned}
e_1 &\leq m_1 - 1 \\
e_2 &\leq m_2 - 1 \\
\cdots \\
e_k &\leq m_k - 1
\end{aligned}
$$

将这 `k` 个不等式相加可以得到：

$$
e_1 + \cdots + e_k \leq m_1 + \cdots + m_k - k = n - k
$$

左侧的 `e1 + ... + ek` 即为图中的边数，右侧的一部分 `m1 + ... + mk = n` 即为图中的节点数。由于我们知道图中至少有 `n - 1` 条边，那么有：

$$
e_1 + \cdots + e_k \geq n - 1
$$

与：

$$
e_1 + \cdots + e_k \leq n - k
$$

产生了矛盾！因此一定存在一个连通分量，它有一条多余的边。我们用这条多余的边连接任意两个连通分量，此时图中的连通分量数变为 `k - 1`。如果 `k - 1 == 1`，那么整个图已经连通，不需要进行其它操作；如果 `k - 1 != 1`，那么我们可以用相同的方法，断定存在一个连通分量有一条多余的边，并用这条边连接任意两个连通分量，以此类推，直到将图中的连通分量数变为 `1`。这样以来，我们使用了 `k - 1` 次操作将整个图连通，也就是将所有计算机进行连接。

综上所述，我们的算法框架如下：

- 比较 `n - 1` 和 `len(connections)`：

  - 如果前者大于后者，那么一定无解，返回 `-1`；

  - 如果前者小于等于后者，那么我们统计出图中的连通分量数 `k`，返回 `k - 1`。

统计图中连通分量数的方法有很多，我们介绍深度优先搜索和并查集两种方法。

#### 方法一：深度优先搜索

我们可以使用深度优先搜索来得到图中的连通分量数。具体地，每个节点的状态为「待搜索」和「已搜索」中的一个，初始时所有节点的状态均为「待搜索」。我们遍历所有的节点，如果找到一个「待搜索」的节点，就从该节点开始进行深度优先搜索，并把所有搜索到的节点标记为「已搜索」，这样就找到了一个连通分量。

```C++ [sol1-C++]
class Solution {
private:
    vector<vector<int>> edges;
    vector<bool> used;

public:
    void dfs(int u) {
        used[u] = true;
        for (int v: edges[u]) {
            if (!used[v]) {
                dfs(v);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        edges.resize(n);
        for (auto&& c: connections) {
            edges[c[0]].push_back(c[1]);
            edges[c[1]].push_back(c[0]);
        }
        used.resize(n);

        int part = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ++part;
                dfs(i);
            }
        }
        
        return part - 1;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        edges = {x: list() for x in range(n)}
        for c0, c1 in connections:
            edges[c0].append(c1)
            edges[c1].append(c0)
        used = set()

        def dfs(u):
            used.add(u)
            for v in edges[u]:
                if v not in used:
                    dfs(v)
        
        part = 0
        for i in range(n):
            if i not in used:
                part += 1
                dfs(i)
        
        return part - 1
```

**复杂度分析**

- 时间复杂度：$O(N + M)$。

- 空间复杂度：$O(N + M)$，我们需要将图中的节点和边存放在额外的数据结构中，以便于进行深度优先搜索。

#### 方法二：并查集

我们也可以使用并查集来得到图中的连通分量数。这里不会具体地介绍并查集本身的实现细节，如果你不了解并查集中的 `findset()` 和 `union()` 这两个操作，请使用搜索引擎，补充这一部分的知识。

并查集其本身就是用来统计连通分量数的数据结构。初始时的连通分量数为 `n`，每当我们使用一次 `union()` 操作，就相当于合并了两个连通分量，连通分量数减少 `1`。

```C++ [sol2-C++]
class Solution {
private:
    vector<int> fa;

public:
    int findset(int x) {
        return x == fa[x] ? x : fa[x] = findset(fa[x]);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        
        int part = n;
        for (auto&& c: connections) {
            int p = findset(c[0]), q = findset(c[1]);
            if (p != q) {
                --part;
                fa[p] = q;
            }
        }

        return part - 1;
    }
};
```

```C++ [sol2-C++17]
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }

        vector<int> fa(n);
        iota(fa.begin(), fa.end(), 0);
        
        function<int(int)> findset = [&](int x) {return x == fa[x] ? x : fa[x] = findset(fa[x]);};

        int part = n;
        for (auto&& c: connections) {
            int p = findset(c[0]), q = findset(c[1]);
            if (p != q) {
                --part;
                fa[p] = q;
            }
        }

        return part - 1;
    }
};
```

```Python [sol2-Python3]
class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        if len(connections) < n - 1:
            return -1
        
        fa = [x for x in range(n)]

        def findset(x):
            if x != fa[x]:
                fa[x] = findset(fa[x])
            return fa[x]
        
        part = n
        for c0, c1 in connections:
            p, q = findset(c0), findset(c1)
            if p != q:
                part -= 1
                fa[p] = q
        
        return part - 1
```

**复杂度分析**

- 时间复杂度：$O(N \log N + M)$，上述代码中的并查集只使用了路径压缩优化，没有使用按秩合并（将较小连通分量合并至较大的连通分量）优化。如果同时使用路径压缩优化和按秩合并优化，时间复杂度降低至 $O(N \alpha(N) + M)$。

- 空间复杂度：$O(N)$。