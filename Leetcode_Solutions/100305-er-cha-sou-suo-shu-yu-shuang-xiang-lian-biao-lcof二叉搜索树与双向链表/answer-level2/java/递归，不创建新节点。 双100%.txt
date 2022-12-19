### 解题思路
递归，保存首节点指针

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
    Node pre = null;
    Node first = null;
    public Node treeToDoublyList(Node root) {
        if(root==null) return null;
        addNode(root);
        first.left=pre;
        pre.right=first;
        return first;
    }
    public void addNode(Node root) {
        if(root==null) return;
        addNode(root.left);
        if(pre!=null){
            root.left = pre;
            pre.right = root;
        }else{
            first=root;
        }
        pre = root;
        addNode(root.right);
    }
}
```