### 预备知识

[**最小生成树**](https://baike.baidu.com/item/最小生成树)
图的生成树是一棵含有其所有的顶点的无环联通子图，一幅加权图的**最小生成树（ MST ）** 是它的一颗权值（树中所有边的权值之和）最小的生成树。

[**并查集**](https://baike.baidu.com/item/并查集)
并查集是一种树型的数据结构，用于处理一些不相交集合的合并及查询问题。在使用中常常以森林来表示。并查集支持两种操作：

- `Find`：确定元素属于哪一个子集。它可以被用来确定两个元素是否属于同一子集。
- `Union`：将两个子集合并成同一个集合。

#### 方法一：kruskal 算法

**思路**

本题要求**为所有房子都供水的最低总成本**，我们把房子看成是图的节点，管道看成是图的边，那么这题很显然就是最小生成树的问题。唯一的区别是可以直接在房子内造水井。

因为只修建管道是没有水的，所以必须在至少一个房子内直接建水井。我们可以假设有一个水库，水库到每一个房子的成本就是房子内建造水井的成本，这样我们就把本题变成了最基础的最小生成树的问题。假设水库的 `id` 为 `0`，那么新的图如下所示：
![fig1](https://assets.leetcode-cn.com/solution-static/1168_fig1.png){:width=300}

我们使用 kruskal 算法，按照边的权重顺序（从小到大）处理所有的边，将边加入到最小生成树中，使用并查集保证加入的边不会与已经加入的边构成环，直到树中含有 `N - 1` 条边为止。

另外，为了优化时间复杂度，我们实现并查集时使用了[路径压缩](https://oi-wiki.org/ds/dsu/#_3)技术，简单地说，就是在查询操作时，将在路径上的每个节点都直接连接到根上，这样就可以节省下次查询的所需的时间。

**算法**

1. 将直接在房子内建造水井变成房子到水库的边加入到图中。
2. 将所有的边按照权重从小到大排序。
3. 取一条权重最小的边。
4. 使用并查集（union-find）数据结构来判断加入这条边后是否会形成环。若不会构成环，则将这条边加入最小生成树中。
5. 检查所有的结点是否已经全部联通，这一点可以通过目前已经加入的边的数量来判断。若全部联通，则结束算法；否则返回步骤 3。

**代码**

```Golang [sol1-Golang]
func minCostToSupplyWater(n int, wells []int, pipes [][]int) int {
    root := make([]int, n + 1)
    for i := 0; i <= n; i++ {
        root[i] = i
    }
    for i := 0; i < len(wells); i++ {
        pipes = append(pipes, []int{0, i+1, wells[i]})
    }
    sort.Slice(pipes, func(i, j int) bool {
        return pipes[i][2] < pipes[j][2]
    })
    sum, num := 0, 0
    for i := 0; i < len(pipes); i++ {
        if num == n {
            break
        }
        if father(pipes[i][0], root) != father(pipes[i][1], root) {
            num++
            sum += pipes[i][2]
            root[father(pipes[i][1], root)] = father(pipes[i][0], root)
        }
    }
    return sum
}

func father(x int, root []int) int {
    if root[x] != x {
        f := father(root[x], root)
        root[x] = f
        return f
    }
    return x
}
```

```cpp [sol1-cpp]
class Solution {
public:
    static constexpr int MAX_N = 10000 + 5;

    int f[MAX_N];

    void init() {
        for (int i = 0; i < MAX_N; ++i) f[i] = i;
    }

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    void merge(int u, int v) {
        f[find(u)] = find(v);
    }

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        init();
        for (int i = 1; i <= n; ++i) pipes.push_back(vector <int> ({0, i, wells[i - 1]}));
        sort(pipes.begin(), pipes.end(), [](const vector <int> &u, const vector <int> &v) {
            return u[2] < v[2];
        });
        int ret = 0;
        for (auto u: pipes) {
            if (find(u[0]) != find(u[1])) {
                merge(u[0], u[1]);
                ret += u[2];
            }
        }
        return ret;
    }
};
```

**复杂度分析**

假设这里给出的边关系的总数是 $e$，我们建成水库之后图上总共的边数为 $n + e$。

- 时间复杂度：$O((n + e) \log (n + e))$，其中 $e$ 为边的数量，$n$ 为房子的数量。排序的时间复杂度为 $O((n + e) \log (n + e))$，我们需要遍历 $(n + e)$ 条边。对于每条边，由于采用了路径压缩技术，查找两个端点的根结点所需的平均时间为 $O(\log n)$，时间复杂度最坏为 $O((n + e) \log n)$。

- 空间复杂度：$O(n + e)$，需要大小为 $n$ 的并查集结构存储点的关系，其中 $n$ 为房子的个数，另外需要存储 $e + n$ 条边。