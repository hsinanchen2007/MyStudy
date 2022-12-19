#### 方法：深度优先搜索

**思路**

尝试将每个人分配到一个组是很自然的想法。假设第一组中的人是红色，第二组中的人是蓝色。

如果第一个人是红色的，那么这个人不喜欢的人必须是蓝色的。然后，任何不喜欢蓝色人的人都是红色的，那么任何不喜欢红色人的人都是蓝色的，依此类推。

如果在任何时候存在冲突，那么这个任务是不可能的完成的，因为从第一步开始每一步都符合逻辑。如果没有冲突，那么着色是有效的，所以答案是 `true`。

**算法**

考虑由给定的 “不喜欢” 边缘形成的 `N` 人的图表。我们要检查这个图的每个连通分支是否为二分的。

对于每个连通的部分，我们只需试着用两种颜色对它进行着色，就可以检查它是否是二分的。如何做到这一点：将任一结点涂成红色，然后将它的所有邻居都涂成蓝色，然后将所有的邻居的邻居都涂成红色，以此类推。如果我们将一个红色结点涂成蓝色（或蓝色结点涂成红色），那么就会产生冲突。


```java [Q59Bm8ZT-Java]
class Solution {
    ArrayList<Integer>[] graph;
    Map<Integer, Integer> color;

    public boolean possibleBipartition(int N, int[][] dislikes) {
        graph = new ArrayList[N+1];
        for (int i = 1; i <= N; ++i)
            graph[i] = new ArrayList();

        for (int[] edge: dislikes) {
            graph[edge[0]].add(edge[1]);
            graph[edge[1]].add(edge[0]);
        }

        color = new HashMap();
        for (int node = 1; node <= N; ++node)
            if (!color.containsKey(node) && !dfs(node, 0))
                return false;
        return true;
    }

    public boolean dfs(int node, int c) {
        if (color.containsKey(node))
            return color.get(node) == c;
        color.put(node, c);

        for (int nei: graph[node])
            if (!dfs(nei, c ^ 1))
                return false;
        return true;
    }
}
```
```python [Q59Bm8ZT-Python]
class Solution(object):
    def possibleBipartition(self, N, dislikes):
        graph = collections.defaultdict(list)
        for u, v in dislikes:
            graph[u].append(v)
            graph[v].append(u)

        color = {}
        def dfs(node, c = 0):
            if node in color:
                return color[node] == c
            color[node] = c
            return all(dfs(nei, c ^ 1) for nei in graph[node])

        return all(dfs(node)
                   for node in range(1, N+1)
                   if node not in color)
```


**复杂度分析**

* 时间复杂度：$O(N + E)$，其中 $E$ 是 `dislikes` 的长度。

* 空间复杂度：$O(N + E)$。