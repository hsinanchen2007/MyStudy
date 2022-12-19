这一题其实相当于第100道题，相同的树的一个变种，那道题是直接比较两个树是否相同，这一题我们可以看成比较第一个节点下面的树结构是否相同，这样解起来就比较简单了。
但是有一点是需要注意的，在求树是否相同的时候，我们计算的是同一侧的值是否相同，而当前这道题目，我们需要求的是镜像的值是否相同，也就是说判断左边的左节点是否跟右边的右节点值相同。

```
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        return isSame(root.left,root.right);
    }

    public boolean isSame(TreeNode left,TreeNode right){
        if(left == null && right == null)return true;
        if(left != null && right != null && left.val == right.val) return isSame(left.left,right.right) && isSame(left.right,right.left); 
        return false;
    }

}
```
