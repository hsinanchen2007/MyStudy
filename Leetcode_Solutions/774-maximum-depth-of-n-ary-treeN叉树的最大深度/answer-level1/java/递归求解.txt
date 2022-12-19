### 解题思路
递归出子节点深度最大的

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public int maxDepth(Node root) {
        if (root == null) {
            return 0;
        } else {
            int max = 0;
            for (Node item : root.children) {
                max = Math.max(max, maxDepth(item));
            }
            return max + 1;
        }
    }
}
```