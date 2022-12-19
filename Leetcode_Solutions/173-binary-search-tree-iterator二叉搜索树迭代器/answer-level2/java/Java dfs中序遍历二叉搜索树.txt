首先把二叉搜索树的值都存储起来，才能做到o(1)访问下个节点。
存储起来可以用数组，队列，都可以。
```
class BSTIterator {

        List<Integer> arr = new ArrayList<>();
        public BSTIterator(TreeNode root) {
            dfs(root);
        }
        private void dfs(TreeNode root){
            if (root == null)return;
            if (root.left != null)
            {
                dfs(root.left);
            }
            arr.add(root.val);
            if (root.right != null){
                dfs(root.right);
            }
        }

        /** @return the next smallest number */
        public int next() {
            return arr.remove(0);
        }

        /** @return whether we have a next smallest number */
        public boolean hasNext() {
            return arr.size() > 0;
        }
}
```