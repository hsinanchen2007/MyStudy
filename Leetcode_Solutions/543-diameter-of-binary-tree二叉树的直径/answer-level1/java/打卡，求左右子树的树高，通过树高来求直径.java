    // 后序遍历 + 求左右子树的树高
    class Solution {
        public int diameterOfBinaryTree(TreeNode root) {
            int[] max = {1};
            dfs(root, max);
            return max[0] - 1;
        }

        public int dfs(TreeNode root, int[] max) {
            if(root == null) {
                return 0;
            }
            int left = dfs(root.left, max);
            int right = dfs(root.right, max);
            max[0] = Math.max(max[0], left + right + 1);
            return Math.max(left, right) + 1;
        }
    }