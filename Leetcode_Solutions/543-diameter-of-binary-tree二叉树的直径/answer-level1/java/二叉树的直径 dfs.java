
题解
1. 求出当前节点的左子树和右子树的深度；left；right；
2. 求出包括当前节点的深度；max(left,right)+1;
3. 当前值 就为左子树+右子树的值；不包括根节点；
```
class Solution {
    int res=0;
    private int dfs(TreeNode root){
        if(root==null){
            return 0;
        }
        int left=dfs(root.left);
        int right=dfs(root.right);
        res=Math.max(left+right+1,res);
        return Math.max(left,right)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null){
            return res;
        }
        dfs(root);
        return res-1;
    }
}
```
