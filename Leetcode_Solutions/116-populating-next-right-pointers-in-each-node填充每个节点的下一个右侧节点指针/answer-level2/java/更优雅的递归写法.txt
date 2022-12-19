感谢@Face to faith
```
public Node connect(Node root) {
        //评论中的递归法：
        if (root == null) {
            return root;
        }
        if (root.right != null) {
            root.left.next = root.right;
            if (root.next != null) {
                root.right.next = root.next.left;
            }
        }
        connect(root.left);
        connect(root.right);
        return root;
    }
```
