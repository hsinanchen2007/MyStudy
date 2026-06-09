### 解题思路
![屏幕快照 2020-02-05 15.42.15.png](https://pic.leetcode-cn.com/a2276e636c473b95979d26fba519b6dcf4f6525b2d800c6e27683b50863a42db-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-05%2015.42.15.png)


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
    public List<Integer> postorder(Node root) {
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
        for (Node n : node.children) {
            dfs(n, res);
        }
        res.add(node.val);
    }
}
```