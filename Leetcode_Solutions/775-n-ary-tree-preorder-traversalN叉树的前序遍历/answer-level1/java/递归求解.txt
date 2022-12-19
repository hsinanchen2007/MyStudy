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
    public List<Integer> preorder(Node root) {
        List<Integer> result = new LinkedList<>();
        recursive(root, result);
        return result;
    }

    public void recursive(Node root, List<Integer> result) {
        if (root != null) {
            result.add(root.val);
            for (Node node : root.children) {
                if (node != null) {
                    recursive(node, result);
                }
            }
        }
    }
}
```