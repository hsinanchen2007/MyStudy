### 解题思路
dfs + 自底向上思路，刷新最大路径

### 代码

```java
class Solution {
    private int max = 0;
    public int longestConsecutive(TreeNode root) {
        if (root == null) {
            return 0;
        }
        dfs(root);
        return max;
    }
    private int dfs(TreeNode root) {
        int leftRel = 1;
        int rightRel = 1;
        if (root.left != null) {
            int rel = dfs(root.left);
            if (root.left.val == root.val + 1) {
                leftRel = rel + 1;
            }
        }
        if (root.right != null) {
            int rel = dfs(root.right);
            if (root.right.val == root.val + 1) {
                rightRel = rel + 1;
            }
        }
        int rel = Math.max(leftRel, rightRel);
        max = Math.max(max, rel);
        return rel;
    }
}
```