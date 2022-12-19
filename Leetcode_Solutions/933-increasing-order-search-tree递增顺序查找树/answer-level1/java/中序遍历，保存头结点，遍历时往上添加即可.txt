![image.png](https://pic.leetcode-cn.com/da9f19530da4805260b385eb4a3c9850f3ba02fdf1967783b758758bbe3ef8d0-image.png)

```
    TreeNode res;
    public TreeNode increasingBST(TreeNode root) {
        res = new TreeNode(0);
        TreeNode t = res;
        helper(root);
        return t.right;
    }
    public void helper(TreeNode root) {
        if(root == null) {
            return;
        }
        helper(root.left);
        TreeNode n = new TreeNode(root.val);
        res.right = n;
        res = n;
        helper(root.right);
    }
```
