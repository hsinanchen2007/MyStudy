```
class Solution {
    public int sumRootToLeaf(TreeNode root) {
        if (root != null) {
            return sum(root, 0);
        }
        return 0;
    }

    int sum(TreeNode root, int i) {
        i <<= 1;
        i += root.val;
        if (root.left == null && root.right == null) {
            return i;
        }
        int res = 0;
        if (root.left != null) {
            res += sum(root.left, i);
        }
        if (root.right != null) {
            res += sum(root.right, i);
        }
        return res;
    }
}
```
