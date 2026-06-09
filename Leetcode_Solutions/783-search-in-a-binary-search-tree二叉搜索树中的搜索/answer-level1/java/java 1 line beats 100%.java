```
class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        return root == null ? null : val == root.val ? root : val < root.val ? searchBST(root.left, val) : searchBST(root.right, val);
    }
}
```
