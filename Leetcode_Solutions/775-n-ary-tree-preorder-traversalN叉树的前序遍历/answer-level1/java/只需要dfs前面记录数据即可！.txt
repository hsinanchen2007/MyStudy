### 解题思路
![屏幕快照 2020-02-05 15.42.15.png](https://pic.leetcode-cn.com/9ecc0421f4f0a686506a183afa3a0dd66c31af54957826b9885412cd6012f66b-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-05%2015.42.15.png)


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
        List<Integer> res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        dfs(root, res);
        return res;
    }

    private void dfs(Node node, List<Integer> res) {
        if (node == null) {
            return;
        }
        res.add(node.val);
        for(Node n : node.children) {
            dfs(n, res);
        }
    }
}
```