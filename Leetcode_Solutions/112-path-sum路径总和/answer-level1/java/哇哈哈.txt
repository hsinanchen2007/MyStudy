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
        if (root == null)
            return false ;
        if (sum==root.val && root.left == null && root.right == null)
            return true ;

        return hasPathSum(root.left , sum - root.val) || hasPathSum(root.right , sum - root.val) ;
    }
}
```