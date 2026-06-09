```
    public Node connect(Node root) {
        if (null == root || null == root.left){
            return root;
        }
        root.left.next = root.right;
        if(root.next != null){root.right.next = root.next.left;}
        connect(root.left);
        connect(root.right);
        return root;
    }
```
