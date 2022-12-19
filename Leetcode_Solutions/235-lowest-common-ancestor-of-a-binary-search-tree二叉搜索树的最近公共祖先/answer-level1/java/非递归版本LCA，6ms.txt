执行用时 :6 ms, 在所有 Java 提交中击败了99.83%的用户

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode node = root;
        while (true) {
            if (p.val > q.val) {
                TreeNode tmp = p; p = q; q = tmp;
            }

            if (node.val == p.val) return node;
            if (node.val == q.val) return node;
            if (p.val < node.val && q.val > node.val) return node;

            node = q.val < node.val ? node.left : node.right;
        }
    }
}
```
