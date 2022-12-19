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
    List<Integer> results = new ArrayList<>();

    public List<Integer> preorder(Node root) {
        if (root == null) {
            return results;
        }
        helper(root);
        return results;
    }

    private void helper(Node root) {
        if (root == null) {
            return;
        }
        results.add(root.val);
        for (Node node : root.children) {
            helper(node);
        }
    }
}
```