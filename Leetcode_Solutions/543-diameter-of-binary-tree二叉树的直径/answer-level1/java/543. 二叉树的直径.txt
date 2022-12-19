```
class Solution {
    int r = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        depth(root);
        return r;
    }
    public int depth(TreeNode TN){//求以TN为根节点的最大深度
        if(TN == null) return 0;
        int LN = depth(TN.left);
        int RN = depth(TN.right);
        if(r <  LN + RN)    r = LN + RN; //计算以当前节点为根的直径，即左右子树深度之和
        return Math.max(LN,RN) + 1;
    }
}
```
