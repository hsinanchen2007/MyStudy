### 解题思路
* 待解析

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
        if (root == null) {
            return 0;
        }
       return depth(root,1);
    }
    private int depth(TreeNode root,int level) {
        if (root == null) {
            return Integer.MAX_VALUE;
        }
        if (root.left == null && root.right == null) {
            return level;
        }
        int left = depth(root.left,level + 1);
        int right = depth(root.right,level + 1);
        return Math.min(left,right);
    }
}
```