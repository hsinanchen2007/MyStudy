### 解题思路
全局boolean 记录 是否平衡
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
    private boolean balanced = true;

  public boolean isBalanced(TreeNode root) {
    treeHeight(root);

    return balanced;
  }

  private int treeHeight(TreeNode node) {
    if (!balanced || node == null) return 0;

    int left = treeHeight(node.left);
    int right = treeHeight(node.right);

    balanced = Math.abs(left - right) > 1 ? false : balanced;

    return Math.max(left, right) + 1;
  }
}
```