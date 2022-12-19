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
    public TreeNode bstToGst(TreeNode root) {
        List<TreeNode> l = new ArrayList<>();
        // dfs, inorder
        h(root, l);
        int sum = 0;
        for(int i = l.size() - 1; i >= 0; -- i) {
            sum += l.get(i).val;
            l.get(i).val = sum;
        }
        return root;
    }

    private void h(TreeNode r, List<TreeNode> l) {
        if(r == null)
            return;
        h(r.left, l);
        l.add(r);
        h(r.right, l);
    }
}
```
