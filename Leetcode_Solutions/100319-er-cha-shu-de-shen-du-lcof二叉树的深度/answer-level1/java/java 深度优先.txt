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
    public int maxDepth(TreeNode root) {
        if (root==null) return 0;
        if (root.left==null&&root.right==null) return 1;
        int ldepth=maxDepth(root.left)+1;
        int rdepth=maxDepth(root.right)+1;
        return ldepth>rdepth?ldepth:rdepth;
    }
}
```