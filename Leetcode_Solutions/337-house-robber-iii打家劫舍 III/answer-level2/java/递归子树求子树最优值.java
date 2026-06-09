### 解题思路


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
    public int rob(TreeNode root) {
        int[] res = helper(root);
        return Math.max(res[0], res[1]);
    }

    /**
     * 递归统计子树的最优值
     * res[0] = 选中根节点的最优值
     * res[1] = 不选跟节点的最优值
     * @param root
     * @return
     */
    private int[] helper(TreeNode root) {
        int[] res = new int[2];
        if (null == root) {
            return res;
        }

        int[] left = helper(root.left);
        int[] right = helper(root.right);

        // 最优值结果的情况
        // 选中根节点, 只能选择子树的非根节点的最优值
        // 不选根节点, 可以选择子树的根节点/非根节点的最优值之和
        res[0] = root.val + left[1] + right[1];
        res[1] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
        return res;
    }
}
```