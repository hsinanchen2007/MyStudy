设置一个全局变量叫做ans，这个ans记录的是最终的结果。

深度优先遍历这棵树的时候，以数组形式返回该节点为根的子树包含的节点数，以及该节点
为根的子树的节点和。

每一次返回之前，用节点和除以节点数然后和ans进行比较，最终就能得到正确答案。

Java 代码：
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public double maximumAverageSubtree(TreeNode root) {
        dfs(root);
        return ans;
    }
    
    double ans = Double.MIN_VALUE;
    public int[]dfs(TreeNode root){
        
        if(root == null)return new int[2];
        int[]left = dfs(root.left);
        int[]right = dfs(root.right);
        int count = left[0]+right[0]+1;
        int val = left[1]+right[1]+root.val;
        ans = Math.max(ans,val*1.0/count);
        return new int[]{count,val};
    }
}
```
