### 解题思路
参考二叉树的后序遍历递归

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
    List<Integer> list=new ArrayList<Integer>();
    public List<Integer> postorder(Node root) {
       if(root==null) return list;
       helper(root) ;
       return list;
    }
    public void helper(Node root){
        if(root==null) return;
        int size=root.children.size();
        for(int i=0;i<size;i++){
            helper(root.children.get(i));
        }
        list.add(root.val);
    }
}
```