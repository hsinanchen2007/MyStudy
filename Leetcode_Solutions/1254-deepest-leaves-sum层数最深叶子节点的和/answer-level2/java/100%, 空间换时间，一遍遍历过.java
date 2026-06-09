```
代码块/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int deepestLeavesSum(TreeNode root) {
        // find the depth and add all
        // one loop
        List<Integer> l = new ArrayList<>();
        t(root, l, 0);
        return l.get(l.size() - 1);
    }

    private void t(TreeNode root, List<Integer> l, int h) {
        if(root == null)
            return;
        if(l.size() == h) {
            l.add(root.val);
        }
        else {
            l.set(h, l.get(h) + root.val);
        }
        t(root.left, l, h + 1);
        t(root.right, l, h + 1);
    }
}
```
