### 解题思路
其中d == 0 和 d == 1用于判断是左子树还是右子树

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
    public TreeNode addOneRow(TreeNode root, int v, int d) {
        if (d == 1) {
            TreeNode newRoot = new TreeNode(v);
            newRoot.left = root;
            return newRoot;
        }
        if (d == 0) {
            TreeNode newRoot = new TreeNode(v);
            newRoot.right = root;
            return newRoot;
        }

        if (root != null && d >= 2) {
            root.left = addOneRow(root.left, v, d == 2 ? 1 : d - 1);
            root.right = addOneRow(root.right, v, d == 2 ? 0 : d - 1);
        }
        return root;
    }
}
```