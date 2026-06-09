#### 方法一：深度优先搜索着色【通过】

**思路**

如果节点属于第一个集合，将其着为蓝色，否则着为红色。只有在二分图的情况下，可以使用贪心思想给图着色：一个节点为蓝色，说明它的所有邻接点为红色，它的邻接点的所有邻接点为蓝色，依此类推。


**算法**

使用数组（或者哈希表）记录每个节点的颜色： `color[node]`。颜色可以是 `0`， `1`，或者未着色（`-1` 或者 `null`）。

搜索节点时，需要考虑图是非连通的情况。对每个未着色节点，从该节点开始深度优先搜索着色。每个邻接点都可以通过当前节点着相反的颜色。如果存在当前点和邻接点颜色相同，则着色失败。

使用栈完成深度优先搜索，栈类似于节点的 “todo list”，存储着下一个要访问节点的顺序。在 `graph[node]` 中，对每个未着色邻接点，着色该节点并将其放入到栈中。

```java []
class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1);

        for (int start = 0; start < n; ++start) {
            if (color[start] == -1) {
                Stack<Integer> stack = new Stack();
                stack.push(start);
                color[start] = 0;

                while (!stack.empty()) {
                    Integer node = stack.pop();
                    for (int nei: graph[node]) {
                        if (color[nei] == -1) {
                            stack.push(nei);
                            color[nei] = color[node] ^ 1;
                        } else if (color[nei] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
}
```

```python []
class Solution(object):
    def isBipartite(self, graph):
        color = {}
        for node in xrange(len(graph)):
            if node not in color:
                stack = [node]
                color[node] = 0
                while stack:
                    node = stack.pop()
                    for nei in graph[node]:
                        if nei not in color:
                            stack.append(nei)
                            color[nei] = color[node] ^ 1
                        elif color[nei] == color[node]:
                            return False
        return True
```

**复杂度分析**

* 时间复杂度：$O(N + E)$，其中 $N$ 是节点的数量，$E$ 是边的数量。着色每个节点时，遍历其所有边。

* 空间复杂度：$O(N)$，存储 `color` 的栈。