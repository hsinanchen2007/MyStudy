### 解题思路
![屏幕快照 2020-02-27 16.53.58.png](https://pic.leetcode-cn.com/4cf938cdc31916a50f59535014ef67cc371261e4e62c715be4ee3f2feeb4b21a-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-27%2016.53.58.png)


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
    // 虚拟头节点
    Node head = new Node(0, null, null);
    // 第二标记位
    Node move = head;

    public Node treeToDoublyList(Node root) {
        if (root == null) {
            return null;
        }
        // 中序遍历
        inorder(root);
        // 将指针循环指向
        move = move.right;
        move.left = head;
        head.right = move;
        return move;
    }

    private void inorder(Node node) {
        if (node == null) {
            return;
        }
        inorder(node.left);
        head.right = new Node(node.val, head, null);
        head = head.right;
        inorder(node.right);
    }
}
```