```
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null) {
            if (q == null) {
                return true;
            } else {
                return false;
            }
        } else {
            if (q == null) {
                return false;
            } else {
                if (p.val != q.val) {
                    return false;
                } else {
                    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
                }
            }
        }
    }
}
```
