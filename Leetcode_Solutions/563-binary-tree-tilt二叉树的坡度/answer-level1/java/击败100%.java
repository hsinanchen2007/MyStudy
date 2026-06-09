class Solution {
    int res = 0;
    public int findTilt(TreeNode root) {
        sum(root);
        return res;
    }
    public int sum(TreeNode root){
        if(root == null)
            return 0;
        int left = sum(root.left);
        int right = sum(root.right);
        res += Math.abs(right-left);
        return left+right+root.val;
    }
}
```