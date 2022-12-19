### 解题思路
从上向下递归处理。
遇到null节点直接返回；遇到非null节点则交换左右子树，然后递归处理左子树和右子树即可。

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
    public TreeNode mirrorTree(TreeNode root) {
        if (root == null) {
            return root;
        }

        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        root.left = mirrorTree(root.left);
        root.right = mirrorTree(root.right);

        return root;
    }
}
```