```java
public class Solution {
    /**
     * key 存原节点，value 存克隆的节点
     * 目的是当节点已克隆过时，可直接对应取出克隆节点的引用
     */
    private Map<Node, Node> map = new HashMap<>();

    public Node cloneGraph(Node node) {
        if (node == null) return null;

        Node clone = new Node(node.val, new ArrayList<>());  //克隆节点
        map.put(node, clone);  //存储原节点和克隆节点的对应关系

        for (Node n : node.neighbors) {
            if (map.containsKey(n)) {
                //该节点已克隆过
                clone.neighbors.add(map.get(n));
            } else {
                //该节点未克隆过，递归调用克隆，将返回的克隆节点添加到 neighbors 中
                clone.neighbors.add(cloneGraph(n));
            }
        }
        return clone;
    }
}
```
