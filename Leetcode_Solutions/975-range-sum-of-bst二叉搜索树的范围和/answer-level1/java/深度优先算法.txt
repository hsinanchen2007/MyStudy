### 解题思路
深度优先算法

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
    public int rangeSumBST(TreeNode root, int L, int R) {
        return  dfs(root,L,R,0);
    }
    private int dfs(TreeNode node, int L, int R, int count) {
        if (node != null) {
            if (L <= node.val && node.val <= R)
                count += node.val;
            if (L < node.val)
                count += dfs(node.left, L, R,0);
            if (node.val < R)
                count +=dfs(node.right, L, R,0);
        }
        return count;
    }
}
```