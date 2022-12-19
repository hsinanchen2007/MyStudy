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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if(d == 1){
            TreeNode ans = new TreeNode(v);
            ans.left = root;
            return ans;
        }
        dfs(root,1,d,v);
        
        return root;
    }
    
    private void dfs(TreeNode root,int dept,int d,int v){
        if(root == null)
            return;
        if(dept + 1 == d){
            TreeNode temp = root.left;
            root.left = new TreeNode(v);
            root.left.left = temp;
            temp = root.right;
            root.right = new TreeNode(v);
            root.right.right = temp;
            return;
        }
        dfs(root.left,dept + 1,d,v);
        dfs(root.right,dept + 1,d,v);
    }
}
```
