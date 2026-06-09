#### 方法一：深度优先搜索【通过】

**思路**

如果两个句子对应的每个单词都相等，或者对应的每个单词之间都存在一条可达路径，那么这两个句子就是相等的。通过深度优先搜索可以确定一个单词到另一个单词之间是否存在可达路径。

**算法**

首先根据 `pairs` 来构建 `图`，再通过深度优先搜索来确定 `w1 = words1[i]` 和 `w2 = words2[i]` 之间是否存在可达路径。

```python [solution1-Python]
class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        if len(words1) != len(words2): return False
        graph = collections.defaultdict(list)
        for w1, w2 in pairs:
            graph[w1].append(w2)
            graph[w2].append(w1)

        for w1, w2 in zip(words1, words2):
            stack, seen = [w1], {w1}
            while stack:
                word = stack.pop()
                if word == w2: break
                for nei in graph[word]:
                    if nei not in seen:
                        seen.add(nei)
                        stack.append(nei)
            else:
                return False
        return True
```

```java [solution1-Java]
class Solution {
    public boolean areSentencesSimilarTwo(
            String[] words1, String[] words2, String[][] pairs) {
        if (words1.length != words2.length) return false;
        Map<String, List<String>> graph = new HashMap();
        for (String[] pair: pairs) {
            for (String p: pair) if (!graph.containsKey(p)) {
                graph.put(p, new ArrayList());
            }
            graph.get(pair[0]).add(pair[1]);
            graph.get(pair[1]).add(pair[0]);
        }

        for (int i = 0; i < words1.length; ++i) {
            String w1 = words1[i], w2 = words2[i];
            Stack<String> stack = new Stack();
            Set<String> seen = new HashSet();
            stack.push(w1);
            seen.add(w1);
            search: {
                while (!stack.isEmpty()) {
                    String word = stack.pop();
                    if (word.equals(w2)) break search;
                    if (graph.containsKey(word)) {
                        for (String nei: graph.get(word)) {
                            if (!seen.contains(nei)) {
                                stack.push(nei);
                                seen.add(nei);
                            }
                        }
                    }
                }
                return false;
            }
        }
        return true;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(NP)$，其中 $N$ 为 `words1` 和 `word2` 长度中的最大值，$P$ 为 `pairs` 的大小。每次搜索都可能要搜索完整个图。 

* 空间复杂度：$O(P)$，其为 `pairs` 的大小。

#### 方法二：并查集 【通过】

**思路**

与 *方法一* 相同，需要判断两个单词之间是否存在可达路径。因此可以将问题转化成找图中的连通分量，用 *并查集* 来做是最适合的。

**算法**  

如果两个单词相似，就将这两个单词之间连上边。根据并查集的模板，将每个 `单词` 映射成一个整数 `ix = index[word]`，之后就可以用 `dsu.find(ix)` 方法找到单词所在的连通分量。

在将 `pairs` 中的单词插入并查集之后，依次取出两个句子的单词 `w1, w2 = words1[i], words2[i]`。检查是否满足 `w1 == w2` 或者 `w1, w2` 在一个连通分量里。

```python [solution1-Python]
class DSU:
    def __init__(self, N):
        self.par = range(N)
    def find(self, x):
        if self.par[x] != x:
            self.par[x] = self.find(self.par[x])
        return self.par[x]
    def union(self, x, y):
        self.par[self.find(x)] = self.find(y)

class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        if len(words1) != len(words2): return False

        index = {}
        count = itertools.count()
        dsu = DSU(2 * len(pairs))
        for pair in pairs:
            for p in pair:
                if p not in index:
                    index[p] = next(count)
            dsu.union(index[pair[0]], index[pair[1]])

        return all(w1 == w2 or
                   w1 in index and w2 in index and
                   dsu.find(index[w1]) == dsu.find(index[w2])
                   for w1, w2 in zip(words1, words2))
```

```java [solution2-Java]
class Solution {
    public boolean areSentencesSimilarTwo(String[] words1, String[] words2, String[][] pairs) {
        if (words1.length != words2.length) return false;
        Map<String, Integer> index = new HashMap();
        int count = 0;
        DSU dsu = new DSU(2 * pairs.length);
        for (String[] pair: pairs) {
            for (String p: pair) if (!index.containsKey(p)) {
                index.put(p, count++);
            }
            dsu.union(index.get(pair[0]), index.get(pair[1]));
        }

        for (int i = 0; i < words1.length; ++i) {
            String w1 = words1[i], w2 = words2[i];
            if (w1.equals(w2)) continue;
            if (!index.containsKey(w1) || !index.containsKey(w2) ||
                    dsu.find(index.get(w1)) != dsu.find(index.get(w2)))
                return false;
        }
        return true;
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

**复杂度分析**

* 时间复杂度：$O(N \log P + P)$，其中 $N$ 为 `words1` 和 `words2` 长度中的最大值，$P$ 为 `pairs` 的大小。如果并查集根据 `rank` 来做级联，复杂度可以提升到 $O(N * \alpha(P) + P) \approx O(N + P)$，其中 $\alpha$ 表示 *阿克曼函数的反函数*。

* 空间复杂度：$O(P)$，其为 `pairs` 的大小。