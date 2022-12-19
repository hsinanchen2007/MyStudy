两种解法
1. BFS，层次遍历，然后依次添加 next 节点即可
2. 递归，每次递归只考虑 leftNode.right 和 rightNode.left 关系

```
    public Node connect(Node root) {
        if (root == null) return root;
        
        Node left = root.left;
        Node right = root.right;
        while(left != null) {
            left.next = right;
            left = left.right;
            right = right.left;
        }
        connect(root.left);
        connect(root.right);
        
        return root;
    }
```
