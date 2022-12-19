![image.png](https://pic.leetcode-cn.com/9211b7dafb01ecab9906f58b10811ee5cc6ba4dd48051f37c7cc8d5cd41b2ba5-image.png)

```
    TreeNode pre = null;
    int res = Integer.MAX_VALUE;
    public int getMinimumDifference(TreeNode root) {
        inOrder(root);
        return res;
    }
    public void inOrder(TreeNode root) {
        if(root == null) {
            return;
        }
        inOrder(root.left);
        if(pre != null) {
            res = Math.min(res, root.val - pre.val);
        }
        pre = root;
        inOrder(root.right);
    }
```
