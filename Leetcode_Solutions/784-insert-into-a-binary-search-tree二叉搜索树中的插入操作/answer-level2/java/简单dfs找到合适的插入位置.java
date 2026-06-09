思路：dfs深搜，找到合适的插入位置就插入值。
```
class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        dfs(root,val);
        return root;
    }
    
    private void dfs(TreeNode root,int val) {
        if (root == null) {
            return;
        }
        // 左右子树都为空，直接插入到合适位置即可
        if (root.left == null && root.right == null) {
            if (val > root.val) {
                root.right = new TreeNode(val);
            }
            
            if (val < root.val) {
                root.left = new TreeNode(val);
            }
            
            return;
        }
        
        // 要插入的值比根节点值大，插入到右子树
        if (val > root.val) {
            if (root.right == null) {
                root.right = new TreeNode(val);
                return;
            }
            
            dfs(root.right,val);
        }
         // 要插入的值比根节点值小，插入到左子树
        if (val < root.val) {
            if (root.left == null) {
                root.left = new TreeNode(val);
                return;
            }
            
            dfs(root.left,val);
        }
    }
}
```