### 解题思路
和二叉树的前序遍历差不多，先遍历左子树，然后依次从左向右遍历节点即可。

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
        List<Integer> list=new ArrayList<Integer>();
        helper(root,list);
        return list;
    }
    public void helper(Node root,List list){
        if(root==null) return;
        list.add(root.val);
        for(Node c:root.children){
            helper(c,list);
        }
    }
}
```