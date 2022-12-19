#### 方法：缓存深度优先搜索法

**思路**

如果 `y` 比 `x` 富有，请考虑带有边 `x -> y` 的有向图。

对于每个人（person `x`），我们都希望最安静的人就在 `x` 的子树中。

**算法**

构建上面所描述的图，并且称 `dfs（person)` 是 `person` 的子树上最安静的人。注意，因为语句在逻辑上是一致的，所以图必须是有向无环图（即，DAG）—— 任意一条边有方向，且不存在环路的图。

现在 `dfs(person)` 可以是 `person`，或者是 `min(dfs(child))`。也就是说，子树中最安静的人可以是 `person` 本身，或者是 `person` 的孩子结点的某个子树中最安静的人。

当执行图的 *后序遍历* 时，我们可以将 `dfs(person)` 的值作为 `answer [person]` 缓存。这样，我们就不会重复工作。该技巧将算法的时间复杂度从平方阶（$O(N^2)$）降低到线性阶（$O(N)$）。

```java [g9dnag2k-Java]
class Solution {
    ArrayList<Integer>[] graph;
    int[] answer;
    int[] quiet;

    public int[] loudAndRich(int[][] richer, int[] quiet) {
        int N = quiet.length;
        graph = new ArrayList[N];
        answer = new int[N];
        this.quiet = quiet;

        for (int node = 0; node < N; ++node)
            graph[node] = new ArrayList<Integer>();

        for (int[] edge: richer)
            graph[edge[1]].add(edge[0]);

        Arrays.fill(answer, -1);

        for (int node = 0; node < N; ++node)
            dfs(node);
        return answer;
    }

    public int dfs(int node) {
        if (answer[node] == -1) {
            answer[node] = node;
            for (int child: graph[node]) {
                int cand = dfs(child);
                if (quiet[cand] < quiet[answer[node]])
                    answer[node] = cand;
            }
        }
        return answer[node];
    }
}
```
```python [g9dnag2k-Python]
class Solution(object):
    def loudAndRich(self, richer, quiet):
        N = len(quiet)
        graph = [[] for _ in xrange(N)]
        for u, v in richer:
            graph[v].append(u)

        answer = [None] * N
        def dfs(node):
            #Want least quiet person in this subtree
            if answer[node] is None:
                answer[node] = node
                for child in graph[node]:
                    cand = dfs(child)
                    if quiet[cand] < quiet[answer[node]]:
                        answer[node] = cand
            return answer[node]

        return map(dfs, range(N))
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 为总人数。

* 空间复杂度：$O(N)$，其中包括了 `answer` 所使用的空间，以及 `dfs` 的隐式调用栈。