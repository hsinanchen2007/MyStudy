### 基本思路
树的直径：从根节点出发，到达最深的节点 A；从节点 A 出发，到达最深的节点 B，此时 A~B 的距离就是树的直径，即以A 为根节点，B 的深度

### 基本步骤
1. 根据输入数据创建 Graph
2. 先以 0 位根节点找到最大深度的点 A
3. 以 A 为根节点找到最大深度的点 B，此时 B 的深度就是树的直径

### 代码
```
Map<Integer, List<Integer>> graphs;

class Node {
    int depth;
    int node;

    public Node(int depth, int node) {
        this.depth = depth;
        this.node = node;
    }
}

public int treeDiameter(int[][] edges) {
    graphs = new HashMap<>();
    /// 构造 Graph，因为是无向图，所以 start -> end, end -> start
    for (int[] edge : edges) {
        int start = edge[0], end = edge[1];
        List<Integer> ends = graphs.get(start);
        if (ends == null) {
            ends = new ArrayList<>();
        }
        ends.add(end);
        graphs.put(start, ends);

        List<Integer> starts = graphs.get(end);
        if (starts == null) {
            starts = new ArrayList<>();
        }
        starts.add(start);
        graphs.put(end, starts);
    }

    Node furthestNodeFormRoot = bfs(0, edges.length);
    Node furthestNodeFormLast = bfs(furthestNodeFormRoot.node, edges.length);
    return furthestNodeFormLast.depth;
}

private Node bfs(int root, int pointCount) {
    boolean[] visited = new boolean[pointCount + 1];
    Queue<Node> queue = new LinkedList<>();
    Node rootNode = new Node(0, root);
    queue.offer(rootNode);
    visited[root] = true;
    Node furthestNode = rootNode;
    while (!queue.isEmpty()) {
        Node node = queue.poll();
        int depth = node.depth;
        if (depth > furthestNode.depth) {
            furthestNode = node;
        }
        List<Integer> ends = graphs.get(node.node);
        if (ends != null) {
            for (Integer end : ends) {
                if (!visited[end]) {
                    queue.add(new Node(depth + 1, end));
                    visited[end] = true;
                }
            }
        }
    }
    return furthestNode;
}
```