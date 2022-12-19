### 解题思路
渣渣思路

二叉树的最长路径=max{左子树的最长路径,右子树的最长路径,经过根结点的最长路径}
经过根结点的最长路径 = 左子树的最大深度+右子树的最大的深度

算法复杂度O(n^2)

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
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null || (root.left == null && root.right == null)) return 0;
        if(root.left == null || root.right == null) return depth(root)-1;
        int i = diameterOfBinaryTree(root.left),
            j = diameterOfBinaryTree(root.right),
            h = depth(root.left) + depth(root.right);

        return Math.max(Math.max(i,j),h);
    }
    //求节点深度
    public int depth(TreeNode node){
        if(node == null) return 0;
        return Math.max( depth(node.left), depth(node.right))+1;
    }
}
```