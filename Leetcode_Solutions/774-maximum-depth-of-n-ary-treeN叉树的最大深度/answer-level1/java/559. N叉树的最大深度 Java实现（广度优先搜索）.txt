### 解题思路
此处撰写解题思路

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
        Queue<Node> q = new LinkedList<>();
        q.add(root);
        int deepth = 0;
        int qSize;
        while (!q.isEmpty()) {
            qSize = q.size();
            while (qSize-- > 0) {
                Node n = q.poll();
                for (Node child : n.children) {
                    q.add(child);
                }
            }
            deepth++;
        }
        return deepth;
    }
}
```