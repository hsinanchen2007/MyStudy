    
    class Solution {
        public TreeNode convertBiNode(TreeNode root) {
            if(root == null){
                return root;
            }
            TreeNode p = root;
            while(p.left != null) {
                p = p.left;
            }
            dfs(root);
            pre.left = null;
            return p;
        }

        public TreeNode pre = null;
        public void dfs(TreeNode root) {
            if(root == null) {
                return;
            }
            dfs(root.left);
            if(pre == null) {
                pre = root;
            }else {
                pre.right = root;
                pre.left = null;
                pre = root;
            }
            dfs(root.right);
        }
    }