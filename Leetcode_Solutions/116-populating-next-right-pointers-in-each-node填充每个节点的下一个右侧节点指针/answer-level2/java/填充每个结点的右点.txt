### 解题思路
1. 自己想的笨方法。
2. 评论中的正规军。

### 代码

```java
/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root == null) return root;
        if(root.left != null) helper(root.left, root.right);
        return root;
    }

    private void helper(Node left, Node right){
        left.next = right;
        if(left.left != null){
            helper(left.left, left.right);
            helper(left.right, right.left);
            helper(right.left, right.right);
        }
    }
}

class Solution {
    public Node connect(Node root) {
        if(root == null || root.left == null) return root;
        root.left.next = root.right;
        if(root.next != null) root.right.next = root.next.left;
        connect(root.left);
        connect(root.right);
        return root;
    } 
}
```