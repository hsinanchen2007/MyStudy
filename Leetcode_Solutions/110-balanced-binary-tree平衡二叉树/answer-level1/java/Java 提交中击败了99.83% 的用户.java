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
        
        if (root == null){
            return true;
        }
        int lefth = countd(root.left);
        int righth = countd(root.right);
        return Math.abs(lefth - righth) <= 1 && isBalanced(root.left) &&isBalanced(root.right);
    }
    private int countd(TreeNode node){
        if (node == null)
            return 0;
        return Math.max(countd(node.left),countd(node.right))+1;
    }
}
```