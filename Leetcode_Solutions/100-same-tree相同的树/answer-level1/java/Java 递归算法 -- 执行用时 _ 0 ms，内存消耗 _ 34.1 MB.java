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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        //如果p和q都为空
        if(p == null && q == null)
            return true;
        //如果p和q不都为空，但有其一为空
        if(p == null || q == null)
            return false;
        //如果p和q的值不相等
        if(p.val != q.val)
            return false;
        //递归运算p和q的左右子节点
        return (isSameTree(p.left, q.left) && isSameTree(p.right, q.right));
    }
}
```