        

        public int pathSum(TreeNode root, int sum) {
            if (root == null) {
                return 0;
            }
            return dfs(root, sum) + pathSum(root.left, sum) + pathSum(root.right, sum);
        }

        public int dfs(TreeNode root, int sum) {
            if (root == null) {
                return 0;
            }
            if (sum - root.val == 0) {
                return dfs(root.left, sum - root.val) + dfs(root.right, sum - root.val) + 1;
            }
            return dfs(root.left, sum - root.val) + dfs(root.right, sum - root.val);
        }