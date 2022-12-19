时间95%
```
class Solution {
    private int ret =0;
    
    public int sumOfLeftLeaves(TreeNode root) {
        //如果递归到null节点，则直接返回0；
        if (root == null) {
            return 0;
        }
        //如果该节点的左子节点为叶子节点，则把其左节点的值加入结果
        if (root.left != null && root.left.left == null && root.left.right == null) {
            ret += root.left.val;
        }
        //递归该节点的左子节点
        sumOfLeftLeaves(root.left);
        //递归该节点的右子节点
        sumOfLeftLeaves(root.right);
        return ret;
    }
}
```
    