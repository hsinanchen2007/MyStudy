没错！我就是来提前占坑的！终于可以在 LeetCode 上刷 剑指offer 了！尤为开心！
```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null || p == root || q == root)return root;
        TreeNode left = lowestCommonAncestor(root.left,p,q);
        TreeNode right = lowestCommonAncestor(root.right,p,q);
        if(left!=null && right != null)return root;
        return left == null ? right : left;
    }
}
```