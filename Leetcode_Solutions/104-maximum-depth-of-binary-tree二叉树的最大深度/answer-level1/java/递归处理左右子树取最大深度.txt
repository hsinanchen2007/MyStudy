### 解题思路

还是通过递归和一个辅助函数完成计算，如果节点不为null则深度加一，然后递归处理左右子树取最大值。

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
    int depth(TreeNode node, int depth) {
        if (node == null) {
            return depth;
        }
        depth += 1;
        if (node.left == null && node.right == null) {
            return depth;
        }
        return Math.max(depth(node.left, depth), depth(node.right, depth));
    }

    public int maxDepth(TreeNode root) {
        return depth(root, 0);
    }
}
```