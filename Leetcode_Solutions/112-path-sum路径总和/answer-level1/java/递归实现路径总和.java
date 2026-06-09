递归思想：
- 先序递归遍历 二叉树， 
- 并将父节点的值 加到左节点或右节点值上，递归左节点或右节点
递归结束条件：
- 找到一条路径等于sum, 即当前节点值等于 sum 返回 true
- 遍历完该二叉树 返回 false

代码：
```
class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        
        boolean left = false, right = false;
        
            if(root.val == sum && root.left == null && root.right == null) return true;
        
            if(root.left != null){
                root.left.val += root.val;
                left  = hasPathSum(root.left, sum);
            }

            if(root.right != null){
                root.right.val += root.val;
               right =  hasPathSum(root.right, sum);
            }   

            return left || right;
    }   
}
```