### 解题思路

前序遍历 （中左右），而且要**不影响二叉树节点之间的关系。**

所以在二叉树左子树为空且右子树为空的情况下要添加一个`()`为左子树的null占位。

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
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        StringBuilder sb = new StringBuilder();
        dfs(t, sb);
        return sb.substring(1, sb.length() - 1);
    }

    private void dfs(TreeNode root, StringBuilder sb) {
        if (root != null) {
            sb.append("(").append(root.val);
            if (root.left == null && root.right != null) {
                sb.append("()");
            }
            dfs(root.left, sb);

            dfs(root.right, sb);
            sb.append(")");
        }
    }
}
```