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
    public List<TreeNode> allPossibleFBT(int N) {
        // recursive
        List<TreeNode> r = new ArrayList<>();
        if(N == 1) {
            r.add(new TreeNode(0));
            return r;
        }
        for(int i = 1; i < N - 1; ++ i) {
            List<TreeNode> lr = allPossibleFBT(i);
            List<TreeNode> rr = allPossibleFBT(N - i - 1);
            for(TreeNode lc : lr) {
                for(TreeNode rc : rr) {
                    TreeNode nr = new TreeNode(0);
                    nr.left = lc;
                    nr.right = rc;
                    r.add(nr);
                }
            }
        }
        return r;
    }
}
```
