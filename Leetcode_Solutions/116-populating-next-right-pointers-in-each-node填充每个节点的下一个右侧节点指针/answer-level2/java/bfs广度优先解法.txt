### 解题思路

使用递归，直接负责当层节点直接的关系即可！

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
        if(root == null) return root;   //如果root为空，则直接返回
        root.next = null;               //先将根节点的next置为null
        helper(root.left,root.right);
        return root;
    }
    public void helper(Node left , Node right){     //按照bfs层级优先来遍历
        if(left == null) return;
        left.next = right;                  //先满足当层的需求
        right.next = null;
        helper(left.left,left.right);       //满足左子树
        helper(left.right,right.left);      //将左子树和右子树连接起来
        helper(right.left,right.right);     //满足右子树
    }
}
```