### 解题思路

- dfs

** 抛异常为什么会慢啊**

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
    public boolean isBalanced(TreeNode root) {

        try {
            getTreeDeep(root);
            return true;
        } catch (Exception e) {
            return false;
        }

    }

    private int getTreeDeep(TreeNode root) {
        if (root != null) {
            // 拿到左子树的高度
            int leftDeep = getTreeDeep(root.left) + 1;
            // 拿到右子树的高度
            int rightDeep = getTreeDeep(root.right) + 1;
            if (Math.abs(leftDeep - rightDeep) > 1) {
                throw new RuntimeException("不是平衡二叉树");
            }
            return Math.max(leftDeep, rightDeep);
        }
        return 0;
    }
}
```