### 解题思路
递归求解

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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
        TreeNode node = null;
        if (t1 == null && t2 == null) {
            return null;
        }
        if (t1 != null && t2 != null) {
            node = new TreeNode(t1.val + t2.val);
        }
        if (t1 == null || t2 == null) {
            node = new TreeNode(t1 != null ? t1.val : t2.val);
        }
        node.left = mergeTrees(t1 != null ? t1.left : null, t2 != null ? t2.left : null);
        node.right = mergeTrees(t1 != null ? t1.right : null, t2 != null ? t2.right : null);
        return node;
    }
}
```