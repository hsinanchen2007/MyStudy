### 解题思路
树的经典递归问题。一颗N叉树的高度就是根节点高度（1）+它所有子树高度最大值。递归截止条件，树是空树，高度为0.
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
        //递归法，树的问题递归就行了
     if(root==null)
        return 0;
    int depth=0;
    for(int i=0;i<root.children.size();i++)
        depth=Math.max(depth,maxDepth(root.children.get(i)));
    return 1+depth;
    }
}
```