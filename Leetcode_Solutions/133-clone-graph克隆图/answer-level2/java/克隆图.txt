#### 方法一：深度优先搜索 DFS

**思想**

> 注意：首先尝试将问题描述的更加清楚，使其便于理解。因为这个问题使我感到困惑，所以我决定编写该问题的题解，希望帮助读者弄清可能会遇到的疑问。

图中一个节点可以拥有任意数量的邻接点。为了避免在复制时陷入死循环，需要了解图的结构。根据问题描述，任何给定的无向边都可以表示为两个有向边。如果节点 `A` 和节点 `B` 之间存在无向边，则它的图表示具有从节点 `A` 到节点 `B` 的有向边和从节点 `B` 到节点 `A` 的有向边。无向图实际上是一组连接在一起的节点，其中所有的边都是双向的。

![](https://pic.leetcode-cn.com/Figures/133/133_Clone_Graph_1.png){:width=400}

为了防止多次遍历同一个节点，避免陷入死循环，需要以某种方式跟踪已经复制的节点。

**算法**

1. 从给定节点开始遍历图。

2. 使用一个 HashMap 存储所有已被访问和复制的节点。HashMap 中的 `key` 是原始图中的节点，`value` 是克隆图中的对应节点。如果某个节点已经被访问过，则返回其克隆图中的对应节点。

    给定边 `A - B`，表示 `A` 能连接到 `B`，且 `B` 能连接到 `A`。如果对访问过的节点不做标记，则会陷入死循环中。

    ![](https://pic.leetcode-cn.com/Figures/133/133_Clone_Graph_2.png){:width=500}

3. 如果当前访问的节点不在 HashMap 中，则创建它的克隆节点存储在 HashMap 中。注意：在进入递归之前，必须先创建克隆节点并保存在 HashMap 中。

    ```python [snippet1-Python]
    clone_node = Node(node.val, [])
    visited[node] = clone_node
    ```

    如果不保证这种顺序，可能会在递归中再次遇到同一个节点，再次遍历该节点时，陷入死循环。

    ![](https://pic.leetcode-cn.com/Figures/133/133_Clone_Graph_3.png){:width=500}

4. 递归调用每个节点的邻接点。每个节点递归调用的次数等于邻接点的数量，每一次调用返回其对应邻接点的克隆节点，最终返回这些克隆邻接点的列表，将其放入对应克隆节点的邻接表中。这样就可以克隆给定的节点和其邻接点。

> 提示：如果在递归调用中传入节点自身会出现什么情况？为什么每次递归调用输入不同的节点，却执行相同的操作。实际上，只需要保证对一个节点的递归调用正确即可，其他的节点也会在递归过程中建立正确的连接关系。

```java [solution1-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    private HashMap <Node, Node> visited = new HashMap <> ();
    public Node cloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.containsKey(node)) {
            return visited.get(node);
        }

        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node cloneNode = new Node(node.val, new ArrayList());
        // The key is original node and value being the clone node.
        visited.put(node, cloneNode);

        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned node.
        for (Node neighbor: node.neighbors) {
            cloneNode.neighbors.add(cloneGraph(neighbor));
        }
        return cloneNode;
    }
}
```

```python [solution1-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution(object):

    def __init__(self):
        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        self.visited = {}

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        if not node:
            return node

        # If the node was already visited before.
        # Return the clone from the visited dictionary.
        if node in self.visited:
            return self.visited[node]

        # Create a clone for the given node.
        # Note that we don't have cloned neighbors as of now, hence [].
        clone_node = Node(node.val, [])

        # The key is original node and value being the clone node.
        self.visited[node] = clone_node

        # Iterate through the neighbors to generate their clones
        # and prepare a list of cloned neighbors to be added to the cloned node.
        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]

        return clone_node
```

**复杂度分析**

* 时间复杂度：$O(N)$，每个节点只处理一次。

* 空间复杂度：$O(N)$，存储克隆节点和原节点的 HashMap 需要 $O(N)$ 的空间，递归调用栈需要 $O(H)$ 的空间，其中 $H$ 是图的深度。总体空间复杂度为 $O(N)$。


#### 方法二：广度优先遍历 BFS

**思路**

考虑到调用栈的深度，使用 BFS 进行图的遍历比 DFS 更好。

![](https://pic.leetcode-cn.com/Figures/133/133_Clone_Graph_4.png){:width=500}

方法一与方法二的区别仅在于 DFS 和 BFS。DFS 以深度优先，BFS 以广度优先。这两种方法都需要借助 HashMap 避免陷入死循环。

**算法**

1. 使用 HashMap 存储所有访问过的节点和克隆节点。HashMap 的 `key` 存储原始图的节点，`value` 存储克隆图中的对应节点。`visited` 用于防止陷入死循环，和获得克隆图的节点。

2. 将第一个节点添加到队列。克隆第一个节点添加到名为 `visited` 的 HashMap 中。

3. BFS 遍历
    - 从队列首部取出一个节点。
    - 遍历该节点的所有邻接点。
    - 如果某个邻接点已被访问，则该邻接点一定在 `visited` 中，那么从 `visited` 获得该邻接点。
    - 否则，创建一个新的节点存储在 `visited` 中。
    - 将克隆的邻接点添加到克隆图对应节点的邻接表中。

```java [solution2-Java]
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {}

    public Node(int _val,List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return node;
        }

        // Hash map to save the visited node and it's respective clone
        // as key and value respectively. This helps to avoid cycles.
        HashMap<Node, Node> visited = new HashMap();

        // Put the first node in the queue
        LinkedList<Node> queue = new LinkedList<Node> ();
        queue.add(node);
        // Clone the node and put it in the visited dictionary.
        visited.put(node, new Node(node.val, new ArrayList()));

        // Start BFS traversal
        while (!queue.isEmpty()) {
            // Pop a node say "n" from the from the front of the queue.
            Node n = queue.remove();
            // Iterate through all the neighbors of the node "n"
            for (Node neighbor: n.neighbors) {
                if (!visited.containsKey(neighbor)) {
                    // Clone the neighbor and put in the visited, if not present already
                    visited.put(neighbor, new Node(neighbor.val, new ArrayList()));
                    // Add the newly encountered node to the queue.
                    queue.add(neighbor);
                }
                // Add the clone of the neighbor to the neighbors of the clone node "n".
                visited.get(n).neighbors.add(visited.get(neighbor));
            }
        }

        // Return the clone of the node from visited.
        return visited.get(node);
    }
}
```

```python [solution2-Python]
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
from collections import deque
class Solution(object):

    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """

        if not node:
            return node

        # Dictionary to save the visited node and it's respective clone
        # as key and value respectively. This helps to avoid cycles.
        visited = {}

        # Put the first node in the queue
        queue = deque([node])
        # Clone the node and put it in the visited dictionary.
        visited[node] = Node(node.val, [])

        # Start BFS traversal
        while queue:
            # Pop a node say "n" from the from the front of the queue.
            n = queue.popleft()
            # Iterate through all the neighbors of the node
            for neighbor in n.neighbors:
                if neighbor not in visited:
                    # Clone the neighbor and put in the visited, if not present already
                    visited[neighbor] = Node(neighbor.val, [])
                    # Add the newly encountered node to the queue.
                    queue.append(neighbor)
                # Add the clone of the neighbor to the neighbors of the clone node "n".
                visited[n].neighbors.append(visited[neighbor])

        # Return the clone of the node from visited.
        return visited[node]
```

**复杂度分析**

* 时间复杂度：$O(N)$，每个节点只处理一次。

* 空间复杂度：$O(N)$。`visited` 使用 $O(N)$ 的空间。BFS 中的队列使用 $O(W)$ 的空间，其中 $W$ 是图的宽度。总体空间复杂度为 $O(N)$。