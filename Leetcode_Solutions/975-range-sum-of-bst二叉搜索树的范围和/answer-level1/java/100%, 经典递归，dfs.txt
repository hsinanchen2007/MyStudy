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
    int res = 0;
    public int rangeSumBST(TreeNode root, int L, int R) {
        // dfs, add all elements between L and R
        h(root, L, R);
        return res;
    }

    private void h(TreeNode root, int L, int R) {
        if(root == null)
            return;

        if(root.val < L && root.val < R) {
            h(root.right, L, R);
            return;
        }

        if(root.val > L && root.val > R) {
            h(root.left, L, R);
            return;
        }

        res += root.val;
        h(root.left, L, R);
        h(root.right, L, R);
    }
}
```
