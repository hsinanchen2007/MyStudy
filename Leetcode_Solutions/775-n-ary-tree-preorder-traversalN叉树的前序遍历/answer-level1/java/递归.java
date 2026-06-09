### 解题思路
从根结点开始
1. 先将根结点值添加到list
2. 在递归从左往右访问孩子结点
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
    private List<Integer> list = new ArrayList<Integer>();
    public List<Integer> preorder(Node root) {
        f(root);
        return list;
    }
    private void f(Node root) {
        if (root == null) {
            return;
        }
        list.add(root.val);
        for (Node node:root.children) {
            f(node);
        }
    }
}
```