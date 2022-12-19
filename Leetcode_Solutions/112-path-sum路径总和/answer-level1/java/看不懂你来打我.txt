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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        sum -= root.val;
        
        if(sum == 0 && root.left == null && root.right == null) return true;
        
        if(root.left == null && root.right == null) return false;

        return hasPathSum(root.left, sum) || hasPathSum(root.right, sum);
    }
}
```