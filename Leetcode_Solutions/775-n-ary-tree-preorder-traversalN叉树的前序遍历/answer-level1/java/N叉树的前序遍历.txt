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
    List<Integer> res=new ArrayList<Integer>();
    public List<Integer> preorder(Node root) {
        //N叉树的前序遍历，先遍历根节点，再递归遍历根节点的所有子树
        if(root==null)
            return res;
        res.add(root.val);
        for(Node child:root.children)
            preorder(child);
        return res;
    }
}
```