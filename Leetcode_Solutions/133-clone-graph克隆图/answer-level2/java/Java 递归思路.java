### 解题思路
递归思路，需要用全局map来保存已经遍历过的node

### 代码

```java
class Solution {
    HashMap<Node, Node> map = new HashMap<>();
    public Node cloneGraph(Node node) {
        return clone(node);
    }

    Node clone (Node node) {
        if (node == null) return node;
        if (map.containsKey(node)) return map.get(node);
        Node newNode = new Node(node.val);
        map.put(node, newNode);
        for (int i = 0; i < node.neighbors.size(); i ++) {
            newNode.neighbors.add(clone(node.neighbors.get(i)));
        }
        return newNode;
    }
}
```