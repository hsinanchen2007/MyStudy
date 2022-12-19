# 递归思想：
- 递归结束条件： 此节点为空 或叶子节点
- 每级递归需要做的事： 将root节点的左右子树反转


```
class Solution {
    public TreeNode invertTree(TreeNode root) {
       //递归结束条件
        if(root == null || (root.right == null && root.left == null) ) 
            return root;
       //临时变量记录左右节点地址
        TreeNode left = root.left;
        TreeNode right = root.right;
        //交换左右节点
        root.right = invertTree(left);
        root.left = invertTree(right);
        return root;
        
    }
}
```