### 解题思路
[Leetcode-Java(240+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_116_connect.java)

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
    /**
     * 解题思路：
     * 总结题意：BFS遍历的时候将每一层的节点用next指针关联起来，难点是只能使用常量级空间
     * 1、将左子树的最后侧，右子树的最左侧连接，同级向下一层层循环
     * 2、同理作用于根节点的左右子树
     *
     * @param root
     * @return
     */
    public Node connect(Node root) {
        if (root == null) return null;
        Node left = root.left;
        Node right = root.right;
        while (left != null) {
            left.next = right;
            left = left.right;
            right = right.left;
        }
        connect(root.left);
        connect(root.right);
        return root;
    }
}
```