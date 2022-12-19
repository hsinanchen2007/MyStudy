### 解题思路
[Leetcode-Java(250+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_133_cloneGraph.java)

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
/**
     * 解题思路：
     * 先花了很大的力气读题目，最后发现就是图的深度遍历，由于每个节点值都是唯一的，用一个HashMap保存遍历过的节点，防止无限循环
     * @param node
     * @return
     */
    public Node cloneGraph(Node node) {
        if (node == null){
            return null;
        }
        HashMap<Integer, Node> map = new HashMap<>();
        Node cloneNode = dfs(node, map);
        return cloneNode;
    }

    private Node dfs(Node node, HashMap<Integer, Node> map) {
        if (map.get(node.val) != null) {
            return map.get(node.val);
        }
        Node cloneNode = new Node();
        cloneNode.val = node.val;
        map.put(node.val, cloneNode);
        if (node.neighbors != null) {
            cloneNode.neighbors = new ArrayList<>();
            for (int i = 0; i < node.neighbors.size(); i++) {
                cloneNode.neighbors.add(dfs(node.neighbors.get(i), map));
            }
        }
        return cloneNode;
    }
}
```