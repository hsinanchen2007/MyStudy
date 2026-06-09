### 解题思路
中序遍历+前驱保存
使用单元素数组在递归中传递前驱节点，并带回head节点

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
    public Node treeToDoublyList(Node root) {
        if (root==null) return null;
        Node[] pre = new Node[1];
        Node[] h = new Node[1];
        dfs(root, pre, h);

        h[0].left = pre[0];
        pre[0].right = h[0];
        return h[0];
    }
    void dfs(Node cur, Node[] pre, Node[] head) {
        if (cur==null) return ;
        if (cur.left==null && pre[0]==null) { //头节点
            head[0] = cur;
        }
        dfs(cur.left, pre, head);
        if (pre[0]!=null) {
            pre[0].right = cur;
        }
        cur.left = pre[0];
        pre[0] = cur;
        dfs(cur.right, pre, head);
    }

}
```