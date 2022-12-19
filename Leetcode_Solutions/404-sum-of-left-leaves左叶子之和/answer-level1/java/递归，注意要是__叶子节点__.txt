执行用时 :0 ms, 在所有 java 提交中击败了100.00%的
用户内存消耗 :34.4 MB, 在所有 java 提交中击败了82.89%的用户

循环递归，注意要是**叶子节点**
```
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) {
            return 0;
        }
        if (root.left != null && root.left.left == null && root.left.right == null) {
            return root.left.val + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
        }
        return sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
    }
```
