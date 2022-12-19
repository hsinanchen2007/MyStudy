### 解题思路
分类讨论递归

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
    public int maxDepth(TreeNode root) 
    {
        if(root==null)
            return 0;
        if(root.left==null && root.right==null)
            return 1;
        int deepleft=maxDepth(root.left);
        int deepright=maxDepth(root.right);
        return deepleft>deepright?(deepleft+1):(deepright+1);
    }
}
```