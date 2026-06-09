![leetcode1.png](https://pic.leetcode-cn.com/fc607c278eb81233a0dda9cf692fc0e8a5bff0293a05d9febac46cba2e60eaed-leetcode1.png)

```
public class Solution_isValidBST {
    public boolean isValidBST(TreeNode root) {
        return getBound(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    private boolean getBound(TreeNode node,long left,long right){
        if(node==null)return true;
        if(node.val<=left||node.val>=right)return false;
        if(getBound(node.left,left,node.val)==false)return false;
        return getBound(node.right,node.val,right);
    }
}
```
