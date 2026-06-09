可以把根节点看作一个很特殊的节点。因为打劫直接相连的房子会引发报警，所以当打劫了根节点后，便不能打劫左右的子节点。那么，就可以把问题简化成打劫根节点与不打劫根节点中求最大值的问题。

```
class Solution {
    public int rob(TreeNode root){
        return doRob(root);
    }
    private int doRob(TreeNode node){
        if (node == null)
            return 0;
        int include = node.val;
        int exclude = doRob(node.left) + doRob(node.right);
        if (node.left != null)
        {
            include += doRob(node.left.left);
            include += doRob(node.left.right);
        }
        if (node.right != null){
            include += doRob(node.right.left);
            include += doRob(node.right.right);
        }
        return Math.max(include,exclude);
    }
}
```
