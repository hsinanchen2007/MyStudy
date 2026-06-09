#### 方法 1：分段

**想法**

让 `W = A[0].length`，显然我们可以在 $O(W)$ 的时间里检查两个 `A` 中单词是否相似。

一种是标准的暴力：对每一对单词，如果相似就用一条边相连。可以用 $O(N^2 W)$ 的时间完成。然后，用 $O(N^2)$ 的时间找到连通块（每个节点最多有 $N-1$ 条边）（或者使用并查集可以做到 $O(N)$ 时间）。总的复杂度为 $O(N^2W)$。

另一种方法是枚举一个单词所有可能的邻居。一个 `word` 最多有 $\binom{W}{2}$ 个邻居，如果 `neighbor` 是一个给定的单词，我们就让 `word` 和 `neighbor` 连一条边。这样，我们可以用 $O(N W^3)$ 的时间建图。再利用 $O(N^2)$ 或者 $O(N)$ 的时间找到连通块的数量。

一个发现就是，在这两个方法中，我们可以选择效果更好的方法。如果只有少数单词，我们希望使用第一个方法；如果单词很短，我们希望使用第二种方法。我们分情况考虑这两种方法，使得最终的复杂度为 $O(NW\min(N, W^2))$。

**算法**

我们会构出一张有 $N$ 个节点的图，点 `i` 和点 `j` 相连当且仅当 `A[i]` 和 `A[j]` 相似，然后找到连通块数量。

这个问题有以下几个挑战，但每个都比较直接：

* 使用一个辅助函数 `similar(word1, word2)` 为 `true` 当且仅当两个单词相似。
* 枚举单词的所有邻居，发现相等的单词。
* 使用深度优先搜索或者并查集，计算连通块的数量。在这个题解中我们使用并查集的结构，评论中有深度优先搜索的注释。

对于更多细节，请看下面的实现。


```Java []
class Solution {
    public int numSimilarGroups(String[] A) {
        int N = A.length;
        int W = A[0].length();
        DSU dsu = new DSU(N);

        if (N < W*W) { // If few words, then check for pairwise similarity: O(N^2 W)
            for (int i = 0; i < N; ++i)
                for (int j = i+1; j < N; ++j)
                    if (similar(A[i], A[j]))
                        dsu.union(i, j);

        } else { // If short words, check all neighbors: O(N W^3)
            Map<String, List<Integer>> buckets = new HashMap();
            for (int i = 0; i < N; ++i) {
                char[] L = A[i].toCharArray();
                for (int j0 = 0; j0 < L.length; ++j0)
                    for (int j1 = j0 + 1; j1 < L.length; ++j1) {
                        swap(L, j0, j1);
                        StringBuilder sb = new StringBuilder();
                        for (char c: L) sb.append(c);
                        buckets.computeIfAbsent(sb.toString(),
                                x-> new ArrayList<Integer>()).add(i);
                        swap(L, j0, j1);
                    }
            }

            for (int i1 = 0; i1 < A.length; ++i1)
                if (buckets.containsKey(A[i1]))
                    for (int i2: buckets.get(A[i1]))
                        dsu.union(i1, i2);
        }

        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (dsu.parent[i] == i) ans++;

        return ans;
    }

    public boolean similar(String word1, String word2) {
        int diff = 0;
        for (int i = 0; i < word1.length(); ++i)
            if (word1.charAt(i) != word2.charAt(i))
                diff++;
        return diff <= 2;
    }

    public void swap(char[] A, int i, int j) {
        char tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
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

```Python []
class DSU:
    def __init__(self, N):
        self.par = range(N)
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    def union(self, x, y):
        self.par[self.find(x)] = self.find(y)

class Solution(object): # (NW) * min(N, W*W) complexity
    def numSimilarGroups(self, A):
        N, W = len(A), len(A[0])

        def similar(word1, word2):
            diff = 0
            for x, y in itertools.izip(word1, word2):
                if x != y:
                    diff += 1
            return diff <= 2

        dsu = DSU(N)

        if N < W*W: # If few words, then check for pairwise similarity: O(N^2 W)
            for (i1, word1), (i2, word2) in \
                    itertools.combinations(enumerate(A), 2):
                if similar(word1, word2):
                    dsu.union(i1, i2)

        else: # If short words, check all neighbors: O(N W^3)
            buckets = collections.defaultdict(set)
            for i, word in enumerate(A):
                L = list(word)
                for j0, j1 in itertools.combinations(xrange(W), 2):
                    L[j0], L[j1] = L[j1], L[j0]
                    buckets["".join(L)].add(i)
                    L[j0], L[j1] = L[j1], L[j0]

            for i1, word in enumerate(A):
                for i2 in buckets[word]:
                    dsu.union(i1, i2)

        return sum(dsu.par[x] == x for x in xrange(N))
```

**复杂度分析**

* 时间复杂度：$O(NW \min(N, W^2))$，其中 $N$ 是 `A` 的长度，`W` 是给定单词的长度。
* 空间复杂度：$O(NW^3)$。当 $N < W^2$ 时，空间复杂度为 $O(N)$。否则，复杂度为 $O(NW^3)$。对于每 $NW^2$ 个邻居都要存储一个长度为 $W$ 的单词。（另外，我们需要 $O(NW^2)$ 个索引，指向 $O(NW^3)$  个元素。）由于在这个情况下 $W^2 <= N$，我们可以认为空间复杂度为 $O(N^2 W)$。