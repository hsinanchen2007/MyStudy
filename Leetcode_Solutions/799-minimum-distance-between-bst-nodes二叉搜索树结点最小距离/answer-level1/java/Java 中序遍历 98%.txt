```
class Solution {
    int min = Integer.MAX_VALUE;
    TreeNode pre = null;
    public int minDiffInBST(TreeNode root) {
        help(root);
        return min;
    }
    
    private void help(TreeNode root) {
        if(root == null) {
            return;
        }
        help(root.left);
        if(pre != null) {
            min = Math.min(root.val - pre.val, min);
        }
        pre = root;
        help(root.right);
    }
}
```