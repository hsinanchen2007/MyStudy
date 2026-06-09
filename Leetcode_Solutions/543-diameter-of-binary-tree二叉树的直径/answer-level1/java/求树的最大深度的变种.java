这道题求树中的最大的直径，其实就是求出当前根节点的左子树的最大深度和右子树的最大的深度，然后左右的最大深度相加就是过这个节点的最大的直径，在递归的过程中找到一个最大值返回就好了
<br>

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
    public int diameterOfBinaryTree(TreeNode root) {
        longestPath(root);
        return res;
    }
    
    int res=0;
    
    public int longestPath(TreeNode root) {
        //如果根节点为空，返回0；
        if(root==null) return 0;
        
        int left=longestPath(root.left);
        int right=longestPath(root.right);
        
        res=Math.max(res,left+right);
        return Math.max(left,right)+1;
    }
}
```