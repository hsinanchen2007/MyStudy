### 解题思路
本题是 `104` 题求最大深度的相反题目

- 相比之下除了递归求解左右子树的深度外，还需要考虑**左右子树是否为空**这个情况

- 如果**有为空**的情况，则直接返回两者深度之和再加上根节点的 `1` 

- 若都**不为空**，则求两者最小深度再加上根节点即可。

### 代码

```java []
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
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 左右子树分别递归求各自的深度
        int left = minDepth(root.left);
        int right = minDepth(root.right);
        // 如果左右子树都为空或者有一方为空，则直接返回两者的深度 + 1即可
        if (root.left == null || root.right == null) {
            return left + right + 1;
        }
        // 若都不为空就选两者最小的深度 + 1 
        return Math.min(left, right) + 1;
    }
}
```