### 解题思路
简单的递归，当前结点的左右皆为null，且当前结点为0，则将当前结点置为null

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
    public TreeNode pruneTree(TreeNode root) {
        return deal(root);
    }

    public TreeNode deal(TreeNode now) {
        if (now == null) return null;
        now.left = deal(now.left);
        now.right = deal(now.right);
        if ((now.left == null) && (now.right == null) && (now.val == 0)) {
            return null;
        }
        return now;
    }
}
```