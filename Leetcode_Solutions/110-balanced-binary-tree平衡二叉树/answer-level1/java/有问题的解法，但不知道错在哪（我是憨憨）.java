### 解题思路
此处撰写解题思路

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
    public boolean isBalanced(TreeNode root) {
        if(root==null) return true;
        int leftHeight=treeHeight(root.left);
        int rightHeight=treeHeight(root.right);
        if(Math.abs(leftHeight-rightHeight)>1) return false;
        return isBalanced(root.left)&&isBalanced(root.right);

    }

    private int treeHeight(TreeNode root){
        if(root==null) return 0;
        int left=treeHeight(root.left);
        int right=treeHeight(root.right);
        return Math.max(left,right)+1 ;
    }
}
