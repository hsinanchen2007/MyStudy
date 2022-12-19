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
    private int max=0;
    public int maxDepth(Node root) {
        helper(root,1);
        return max;
    }
    private void helper(Node node,int depth){
        if (node==null)
            return;
        max=Math.max(max,depth);
        for (Node i:node.children){
            helper(i,depth+1);
        }
    }
}
```