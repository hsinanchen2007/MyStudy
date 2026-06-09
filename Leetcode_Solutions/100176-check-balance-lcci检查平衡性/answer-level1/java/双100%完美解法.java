### 解题思路
很简单就看代码吧

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
        if(root==null)
        {
            return true;
        }
       return (Math.abs(height(root.left)-height(root.right))<=1)&&isBalanced(root.right)&&isBalanced(root.left);
     }
     int height(TreeNode root)
     {
         if(root==null)
         return 0;
         return Math.max(height(root.left),height(root.right))+1;
     }
}
```