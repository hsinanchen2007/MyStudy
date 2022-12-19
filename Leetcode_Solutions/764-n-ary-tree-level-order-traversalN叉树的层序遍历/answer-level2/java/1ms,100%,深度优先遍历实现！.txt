### 解题思路
![屏幕快照 2020-02-29 14.44.04.png](https://pic.leetcode-cn.com/65e420382c1fb5222eaab390be5c8d7886910741268c3beaa468aabbd9f331cd-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-29%2014.44.04.png)


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

    List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> levelOrder(Node root) {
        dfs(root, 0);
        return res;
    }
    
    private void dfs(Node node, int level) {
        if (node == null) {
            return;
        }
        if (res.size() == level) {
            List<Integer> list = new ArrayList<>();
            list.add(node.val);
            res.add(list);
        } else {
            res.get(level).add(node.val);
        }
        for (Node n : node.children) {
            dfs(n, level + 1);
        }
    }
}
```