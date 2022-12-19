

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
    int max = 0;
    public int diameterOfBinaryTree(TreeNode root) {
        searchSubtree(root);
        return max;
    }

    public int searchSubtree(TreeNode root) {
        if (root == null)
            return 0;
        // 分别遍历左右子树直至最底层，再回溯
        int leftDepth = searchSubtree(root.left);
        int rightDepth = searchSubtree(root.right);
        // 记录该节点子树的最大深度
        int depth = Math.max(leftDepth, rightDepth);
        max = Math.max(max, leftDepth + rightDepth);
        // 回溯至上一个节点，最大深度自然要+1
        return depth + 1;
    }
}
```