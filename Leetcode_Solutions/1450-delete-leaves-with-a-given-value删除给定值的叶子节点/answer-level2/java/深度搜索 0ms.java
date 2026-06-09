直接深度搜索，代码很清晰的
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
    int target;
    public boolean helper(TreeNode cur){
        if (cur.left != null)
            if (dfs(cur.left))
                cur.left = null;
        if (cur.right != null)
            if (dfs(cur.right))
                cur.right = null;
        if (cur.left == null && cur.right == null){
            if (cur.val == target)
                return true;
            else 
                return false;
        }
        return false;
    }
    public TreeNode removeLeafNodes(TreeNode root, int target) {
        this.target = target;
        if (helper(root))
            return null;
        return root;
    }
}
```
