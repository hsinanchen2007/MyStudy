### 解题思路
层序遍历，遍历有多少层

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
        }
        if (root.children.size() == 0) {
            return 1;
        }
        int dep =0;
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        while (!queue.isEmpty()) {
            int count = queue.size();
            dep++;
            while (count >0) {
                Node node = queue.remove();
                if (node.children.size() != 0) {
                    queue.addAll(node.children);
                }
                count--;
            }
        }
        return dep;
    }
}
```