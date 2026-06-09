```
class Solution {
    int prev;
    boolean start=false;
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        boolean b1=isValidBST(root.left);
        if(start&&prev>=root.val) return false;
        prev=root.val;
        start=true;
        boolean b2=isValidBST(root.right);
        return b1&&b2;
    }
}
```
