### 解题思路
1、设置初始高度
2、递归左右子树更新高度
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
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        //到达叶子节点 返回1 用来增加高度的记录值
        if (root.left == null && root.right == null) {
            return 1;
        }
        //初始将高度d设置为最大int
        int d = Integer.MAX_VALUE;
        //递归左右子树高度 并更新d值
        if (root.left != null) {
            d = Math.min(d, minDepth(root.left));
        }
        if (root.right != null) {
            d = Math.min(d, minDepth(root.right));
        }
        return d + 1;
    }
}
```