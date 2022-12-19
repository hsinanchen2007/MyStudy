#### 方法一： 深度优先搜索

**思路**

首先将处于同一行或同一列的石头两两相连，这样会产生一个图。在这个图里面，互相连通的石子组成一个连通分量。

显然，总有办法将一个连通分量中的石子依次移除，直到只剩下一个。首先，我们要知道每个石子都属于一个连通分量，同时在一个连通分量中移除石子不会影响到其他的连通分量。在有了这个前提之下，我们可以推断出，如果把连通分量作为一个生成树来看，每次都移除树中的叶子节点，重复这个操作，最后就只会剩下一个根节点。

**算法**

在这里我们用深度优先搜索来计算图中的连通分量的个数，通过深度优先搜索遍历连通分量中的每个节点。在每个连通分量里面，最多能移除石子的数量为 `连通分量中石子数量 - 1`。

```java [solution1-Java]
class Solution {
    public int removeStones(int[][] stones) {
        int N = stones.length;

        // graph[i][0] = the length of the 'list' graph[i][1:]
        int[][] graph = new int[N][N];
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    graph[i][++graph[i][0]] = j;
                    graph[j][++graph[j][0]] = i;
                }

        int ans = 0;
        boolean[] seen = new boolean[N];
        for (int i = 0; i < N; ++i) if (!seen[i]) {
            Stack<Integer> stack = new Stack();
            stack.push(i);
            seen[i] = true;
            ans--;
            while (!stack.isEmpty()) {
                int node = stack.pop();
                ans++;
                for (int k = 1; k <= graph[node][0]; ++k) {
                    int nei = graph[node][k];
                    if (!seen[nei]) {
                        stack.push(nei);
                        seen[nei] = true;
                    }
                }
            }
        }

        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def removeStones(self, stones):
        graph = collections.defaultdict(list)
        for i, x in enumerate(stones):
            for j in xrange(i):
                y = stones[j]
                if x[0]==y[0] or x[1]==y[1]:
                    graph[i].append(j)
                    graph[j].append(i)

        N = len(stones)
        ans = 0

        seen = [False] * N
        for i in xrange(N):
            if not seen[i]:
                stack = [i]
                seen[i] = True
                while stack:
                    ans += 1
                    node = stack.pop()
                    for nei in graph[node]:
                        if not seen[nei]:
                            stack.append(nei)
                            seen[nei] = True
                ans -= 1
        return ans
```

**复杂度分析**

* 时间复杂度： $O(N^2)$，其中 $N$ 是石头的数量。

* 空间复杂度： $O(N^2)$。

#### 方法二： 并查集

**思路**

在方法一中，我们通过深度优先搜索来计算隐式图中连通分量的个数。实际上有更高效的解决方法，那就是用并查集。

**算法**

对于一个坐标为 `(i, j)` 的石子来说，需要把行 `i` 和列 `j` 合并，因为并查集是一维的，用 `j+10000` 来代替 `j`。在将所有石子的行和列都合并好之后，只需数一下并查集中有几个集合就可以得到答案了。

简洁起见，这里实现的并查集就不根据 `rank` 来合并了。因此渐进复杂度会比用 `rank` 的高一点。

```java [solution2-Java]
class Solution {
    public int removeStones(int[][] stones) {
        int N = stones.length;
        DSU dsu = new DSU(20000);

        for (int[] stone: stones)
            dsu.union(stone[0], stone[1] + 10000);

        Set<Integer> seen = new HashSet();
        for (int[] stone: stones)
            seen.add(dsu.find(stone[0]));

        return N - seen.size();
    }
}

class DSU {
    int[] parent;
    public DSU(int N) {
        parent = new int[N];
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    public int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    public void union(int x, int y) {
        parent[find(x)] = find(y);
    }
}
```

```python [solution2-Python]
class DSU:
    def __init__(self, N):
        self.p = range(N)

    def find(self, x):
        if self.p[x] != x:
            self.p[x] = self.find(self.p[x])
        return self.p[x]

    def union(self, x, y):
        xr = self.find(x)
        yr = self.find(y)
        self.p[xr] = yr

class Solution(object):
    def removeStones(self, stones):
        N = len(stones)
        dsu = DSU(20000)
        for x, y in stones:
            dsu.union(x, y + 10000)

        return N - len({dsu.find(x) for x, y in stones})
```


**复杂度分析**

* 时间复杂度： $O(N \log N)$，其中 $N$ 是 `stones` 的大小。（如果根据 `rank` 来做合并操作，时间复杂度就是 $O(N * \alpha(N))$，其中 $\alpha$ 是 Ackerman 函数的反函数。）

* 空间复杂度： $O(N)$。