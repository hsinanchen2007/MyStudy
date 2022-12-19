class Solution {


    public int maxDepth(TreeNode root) {

        if(root == null){
            return 0;
        }
        /* 自顶向下 */
        return Math.max(maxDepth(root.left) + 1, maxDepth(root.right) + 1);
        /* 自底向上 */
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }
}