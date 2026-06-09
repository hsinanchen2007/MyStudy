### 解题思路
- 对于【1，2】这个例子无法处理的问题，需要考虑
-  左右节点为空，左右节点一个为空的情况进行解决

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
    public int minDepth(TreeNode root) {
        if(root == null) return 0;
        if(root.left == null && root.right == null) return 1;
        int height_l = minDepth(root.left);
        int height_r = minDepth(root.right);
        if(root.left == null || root.right == null) return height_r+height_l+1;
        return Math.min(height_l,height_r) + 1;

    }
}
```