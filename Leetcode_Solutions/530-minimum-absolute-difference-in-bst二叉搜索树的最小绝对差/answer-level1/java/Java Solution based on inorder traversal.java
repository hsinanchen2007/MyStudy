As we know, inorder traversal of binary tree is sorted in asending order, which means we can use every contineous two elements to compute the min difference val.

```
    public int getMinimumDifference(TreeNode root) {
        int minDiff = Integer.MAX_VALUE;
        if (root != null) {
            Stack<TreeNode> s = new Stack<>();
            TreeNode p = root;
            TreeNode pre = null;
            while (p != null || !s.isEmpty()) {
                if (p != null) {
                    s.push(p);
                    p = p.left;
                } else {
                    p = s.pop();
                    if (pre != null) {
                        if (p.val - pre.val < minDiff) {
                            minDiff = p.val - pre.val;
                        }
                    }
                    pre = p;
                    p = p.right;
                }
            }
        }
        return minDiff;
    }
```
