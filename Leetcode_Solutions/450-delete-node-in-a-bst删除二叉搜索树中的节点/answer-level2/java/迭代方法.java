```java
public TreeNode deleteNode(TreeNode root, int val) {
        TreeNode cur = root, parent = root;
        while (cur != null && cur.val != val){
            parent = cur;
            if (val < cur.val) cur = cur.left;
            else cur = cur.right;
        }
        if (cur == null) return root;
        if (cur.left == null){
            if (cur == root) root = root.right;
            else if (cur == parent.left) parent.left = cur.right;
            else if (cur == parent.right) parent.right = cur.right;
        }else if (cur.right == null){
            if (cur == root) root = root.left;
            else if (cur == parent.left) parent.left = cur.left;
            else if (cur == parent.right) parent.right = cur.left;
        }else{
            TreeNode successor = cur.right,prev = successor;
            for(; successor.left != null; successor=successor.left)
                prev = successor;
            successor.left = cur.left;
            if (prev != successor) prev.left = successor.right;
            if (prev != successor) successor.right = cur.right;
            if (cur == root) root = successor;
            if (cur == parent.left) parent.left = successor;
            else parent.right = successor;
        }
        return root;
    }

```