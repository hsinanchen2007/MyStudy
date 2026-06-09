```
class Solution {
    public int minDepth(TreeNode root) {
        return mindepth(root);
    }
    public int mindepth(TreeNode root){
        if(root==null)return 0;//空树
        if(root.left==null&&root.right==null)return 1;//只有根节点
        int left_height=minDepth(root.left);
        int right_height=minDepth(root.right);
        if(left_height==0||right_height==0)//只有左子树或者只有右子树的情况
           return Math.max(left_height,right_height)+1;//直接找最大深度，此时最大深度即为最小深度
        return Math.min(left_height,right_height)+1;
    }
}
```
