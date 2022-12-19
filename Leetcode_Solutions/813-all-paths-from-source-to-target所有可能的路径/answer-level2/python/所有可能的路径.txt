#### 递归：

题目中给出的图是有向无环的，那么我们可以通过深度优先搜索的方法，递归求解出所有的路径。

设图中有 `N` 个节点，在搜索时，如果我们到达了节点 `N - 1`，那么此时的路径就为 `{N - 1}`；否则如果我们到达了其它的节点 `node`，那么路径就为 `{node}` 加上 `{所有从 nei 到 N - 1}` 的路径集合，其中 `nei` 是 `node` 直接相邻的节点。

```Java [sol1]
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        return solve(graph, 0);
    }

    public List<List<Integer>> solve(int[][] graph, int node) {
        int N = graph.length;
        List<List<Integer>> ans = new ArrayList();
        if (node == N - 1) {
            List<Integer> path = new ArrayList();
            path.add(N-1);
            ans.add(path);
            return ans;
        }

        for (int nei: graph[node]) {
            for (List<Integer> path: solve(graph, nei)) {
                path.add(0, node);
                ans.add(path);
            }
        }
        return ans;
    }
}
```

```Python [sol1]
class Solution(object):
    def allPathsSourceTarget(self, graph):
        N = len(graph)

        def solve(node):
            if node == N-1: return [[N-1]]
            ans = []
            for nei in graph[node]:
                for path in solve(nei):
                    ans.append([node] + path)
            return ans

        return solve(0)
```

**复杂度分析**

* 时间复杂度：$O(2^N*N^2)$。在最坏情况下，路径的数目是指数级别的，且代码中的 `path.add(0, node)` 对于一条路径需要的时间复杂度为 $O(N^2)$，因为在列表的开始位置插入节点的时间复杂度为 $O(N)$。这里存在优化的空间，例如可以改为在列表的结束位置插入节点，时间复杂度降低为 $O(1)$，在返回答案前，将所有列表翻转，这样均摊到列表中的每一个位置仍然是 $O(1)$ 的，因此总时间复杂度可以降低为 $O(2^N *N)$。

* 空间复杂度：$O(2^N*N)$，为在最坏情况下存储所有答案需要的空间。