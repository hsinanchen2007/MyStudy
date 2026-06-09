### 解题思路
和N叉树的前序遍历思路一样，先遍历根节点的所有子树，再遍历根节点。递归结束条件是该点为空树。

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
    public List<Integer> postorder(Node root) {
        if(root==null)
            return res;
        for(Node child:root.children)  //先递归后序遍历子树
            postorder(child);
        res.add(root.val);
        return res;
    }
}
```