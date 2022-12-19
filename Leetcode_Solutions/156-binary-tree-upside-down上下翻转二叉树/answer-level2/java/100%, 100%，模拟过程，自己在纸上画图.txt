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
    TreeNode nr = null;
    public TreeNode upsideDownBinaryTree(TreeNode root) {
        // 又是这道奇怪无比的题目。。。
        // 直接倒过来
        // 左边是新的根，右边变成左边
        // recursive
        h(root);
        return nr;
    }

    private void h(TreeNode r) {
        if(r == null)
            return;
        if(r.left == null) {
            nr = r;
            return;
        }
        h(r.left);
        r.left.left = r.right;
        r.left.right = r;
        r.left = null;
        r.right = null;
        return;
    }
}
```
