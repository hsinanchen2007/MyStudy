### 解题思路
使用二叉搜索树特性优化搜索效率

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null) return null;
        if (p == null) return q;
        if (q == null) return p;
        int max = Math.max(p.val, q.val);
        int min = Math.min(p.val, q.val);
        return LowestCommonAncestor(root, max, min);
    }

    public TreeNode LowestCommonAncestor(TreeNode root, int max, int min)
    {
        if (root == null) return null;
        if (root.val >= min && root.val <= max) return root;
        if (root.val > max)
            return LowestCommonAncestor(root.left, max, min);
        else
            return LowestCommonAncestor(root.right, max, min);
    }
}
```