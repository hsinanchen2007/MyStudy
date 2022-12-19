```
    public boolean isSubtree(TreeNode s, TreeNode t) {
        return s != null && t != null && (equals(s, t) || isSubtree(s.left, t) || isSubtree(s.right, t));
    }

    public boolean equals(TreeNode a, TreeNode b) {
        return (a == null && b == null) || (a != null && b != null && a.val == b.val && equals(a.left, b.left) && equals(a.right, b.right));
    }
```
先序遍历法，
先序遍历树s，如果当前节点的树与树t相同则返回true，否则递归节点左右子树；

判断相同方法：如果当前节点值相同，则递归判断左右子节点的值，如果不同则返回false，如果都为null则返回true