### 解题思路  写一个方法求得一个根节点的左右两边相同值路径的最大值。
  另外设一变量存值相等的路径最大值，一直更新其最大值，


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
class Solution {
    int count;
    public int longestUnivaluePath(TreeNode root) {
        if(root==null) return 0;
        maxLength(root);
        return count;
        
    }
    private int maxLength(TreeNode root){//返回值是左子树或右子树中相同值的个数
        if(root==null) return 0;
        int left=maxLength(root.left);
        int right=maxLength(root.right);
        int maxLeft=0,maxRight=0;
        if(root.left!=null&&root.left.val==root.val)
            maxLeft=left+1;
        if(root.right!=null&&root.right.val==root.val)
            maxRight=right+1;
        count=Math.max(count,maxLeft+maxRight);
        return Math.max(maxLeft,maxRight);
    }
}
```