```java
public int countNodes(TreeNode root) {
    if (root==null) return 0;
    if (root.left==null)    return 1;
    if (root.left!=null && root.right==null)    return 2;
    return countNodes(root.left)+countNodes(root.right)+1;
}
```
