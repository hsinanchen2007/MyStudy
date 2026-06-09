### 解题思路
BFS遍历法
先创建新的结点
再连接边

### 代码

```java
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
            return null;
        }
        Set<Node> nodes = getNodes(node);
        Map<Node, Node> map = new HashMap<>();
        //先创建新的节点
        for (Node n : nodes) {
            Node newNode = new Node();
            newNode.val = n.val;
            newNode.neighbors = new ArrayList<>();
            map.put(n, newNode);
        }
        //再关联所有的边
        for (Node n : map.keySet()) {
            Node newNode = map.get(n);

            for (Node neighbor : n.neighbors) {
                newNode.neighbors.add(map.get(neighbor));
            }
        }
        return map.get(node);
    }

    private Set<Node> getNodes(Node node) {
        Set<Node> res = new HashSet<>();
        Queue<Node> queue = new LinkedList<>();
        queue.add(node);
        res.add(node);
        while (!queue.isEmpty()) {
            node = queue.poll();
            for (Node neighbor : node.neighbors) {
                if (!res.contains(neighbor)) {
                    queue.add(neighbor);
                    res.add(neighbor);
                }
            }
        }

        return res;
    }
}
```