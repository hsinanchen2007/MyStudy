### 解题思路
先求出树的最大高度,在搜索找到最高层的叶子节点,值相加即可

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
    public int deepestLeavesSum(TreeNode root) {
        return dfs(root, 1, maxHight(root));
    }

    /**
    *   树的最大高度
    */
    private int maxHight(TreeNode x) {
        if (x == null) {
            return 0;
        }
        if (x.left == null && x.right == null) {
            return 1;
        }
        int leftH = maxHight(x.left);
        int rightH = maxHight(x.right);
        return (leftH > rightH ? leftH : rightH) + 1;
    }

    /**
    *   搜索叶子节点,将结果相加
    *   h       当前层数
    *   maxH    树的最大高度
    */
    private int dfs(TreeNode x, int h, int maxH) {
        if (x == null) {
            return 0;
        }
        if (h == maxH) {
            return x.val;
        }
        int ans = dfs(x.left, h + 1, maxH) + dfs(x.right, h + 1, maxH);
        return ans;
    }
}
```