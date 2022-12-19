```java
class Solution {
    private TreeNode nRoot = new TreeNode(0);
    private TreeNode node = nRoot;

    public TreeNode increasingBST(TreeNode root) {
        if (root == null) {
            return null;
        }
        increasingBST(root.left);
        root.left = null;
        node.right = root;
        node = node.right;
        increasingBST(root.right);
        return nRoot.right;
    }
}
```
