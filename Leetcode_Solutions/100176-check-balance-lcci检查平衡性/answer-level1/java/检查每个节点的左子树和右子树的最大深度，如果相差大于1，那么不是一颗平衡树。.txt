```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        //拿到节点的左子树和右子树的深度
        int deptLeft = getDept(root.left, 0);
        int deptRight = getDept(root.right, 0);
        //如果相差大于1，那么不是一颗平衡树
        if (Math.abs(deptLeft - deptRight) > 1)
            return false;
        //递归检查这个节点的左子节点和右子节点
        return isBalanced(root.left) && isBalanced(root.right);
    }
    //获取从某个节点开始的深度
    private int getDept(TreeNode root, int dept) {
        if (root == null)
            return dept;
        int deptLeft = getDept(root.left, dept + 1);
        int deptRight = getDept(root.right, dept + 1);
        
        return Math.max(deptLeft, deptRight);
    }
}
```
