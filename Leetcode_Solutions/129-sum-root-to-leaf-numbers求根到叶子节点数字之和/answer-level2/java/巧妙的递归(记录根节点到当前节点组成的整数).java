
```
class Solution {
    public int sumNumbers(TreeNode root, int n){
        n = 10 * n + root.val;
        if(root.left == null && root.right == null) return n;
        int res = 0;
        if(root.left != null) res += sumNumbers(root.left, n);
        if(root.right != null) res += sumNumbers(root.right, n);
        return res;
        
    }

    public int sumNumbers(TreeNode root) {
        if(root == null) return 0;
        return sumNumbers(root, 0);
    }
}
```
