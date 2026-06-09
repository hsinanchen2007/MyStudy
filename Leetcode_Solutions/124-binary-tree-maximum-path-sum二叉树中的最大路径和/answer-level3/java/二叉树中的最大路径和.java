### 解题思路
1. 做完这个题，有所感想。对于二叉树的题，无论简单还是困难，都是基于二叉树的几种遍历切入：先序遍历，中序遍历，后序遍历，层次遍历。
2. 对于本题，需要保持中间的状态，所以使用一个全局变量max保存中间的最大值。因为在中间时刻返回时，返回的是当前点向上提供的最大路径（经过当前点），不一定是内部的最大路径。
3. 基于后序遍历，计算左孩子的最大路径和右孩子的最大路径，再计算经过当前根节点的最大路径，取最大值保存。同时返回当前点和（左孩子或者右孩子最大路径）的和以及当前点自身，三者的最大值。
4. 对于solution2，对1的代码进行了很大的改进。针对1中难搞的负数，2直接使用了Math.max(0,dp())进行初始化。然后在返回时，可以简化代码，详情看代码。
### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution1 {
    int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        int noRes = dp(root);
        return max > noRes ? max : noRes;
    }

    public int dp(TreeNode root){
        if(root.left == null && root.right == null) return root.val;
        int maxPathOfLeft = Integer.MIN_VALUE, maxPathOfRight = Integer.MIN_VALUE, maxPathOfRoot = root.val, sumLeft = Integer.MIN_VALUE, sumRight = Integer.MIN_VALUE;
        
        if(root.left != null) maxPathOfLeft = dp(root.left);
        if(root.right != null) maxPathOfRight = dp(root.right);
        
        if(maxPathOfLeft > 0){
            maxPathOfRoot += maxPathOfLeft;
            sumLeft = maxPathOfLeft + root.val;
        }
        if(maxPathOfRight > 0){
            maxPathOfRoot += maxPathOfRight;
            sumRight = maxPathOfRight + root.val;
        }
        max = Math.max(Math.max(Math.max(maxPathOfLeft, maxPathOfRight), maxPathOfRoot), max);

        return Math.max(Math.max(sumLeft, sumRight), root.val);
    }
}

class Solution2 {
    int max = Integer.MIN_VALUE;
    public int maxPathSum(TreeNode root) {
        dp(root);
        return max;
    }

    public int dp(TreeNode root){
        if(root == null) return 0; //判断出口
        
        int maxPathOfLeft = Math.max(0, dp(root.left));
        int maxPathOfRight = Math.max(0, dp(root.right));
        
        max = Math.max(max, root.val+maxPathOfLeft+maxPathOfRight); // 因为判断出口和1不同，所以这里可以这么写。因为判断以当前节点为根节点的路径的最大值。

        return Math.max(maxPathOfLeft, maxPathOfRight) + root.val;
    }
}
```