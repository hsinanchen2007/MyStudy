我看了其他的用DFS的题解，我的解法区别主要在于对Node(val,null)的场景进行了兼容，其他的题解都会报空指针，还有就是保存Map时使用HashCode节省空间。
```
class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) {
            return null;
        }
        Map<Integer, Node> clonedMap = new HashMap<>();
        return cloneNode(node, clonedMap);
    }

    private Node cloneNode(Node node, Map<Integer, Node> clonedMap) {
        // 已复制的节点直接返回
        if (clonedMap.containsKey(node.hashCode())) {
            return clonedMap.get(node.hashCode());
        }
        Node clonedNode = new Node(node.val, null);
        clonedMap.put(node.hashCode(), clonedNode);
        if (node.neighbors != null) {
            clonedNode.neighbors = new ArrayList<Node>();
            for (Node neighbor : node.neighbors) {
                clonedNode.neighbors.add(cloneNode(neighbor, clonedMap));
            }
        }
        return clonedNode;
    }
}
```
