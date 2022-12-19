### 解题思路

x 节点的left和right以及parent是3个子数，本质上就是找到这三个树里面最大的节点树超没超过n / 2

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
    int left, right, x;
    public boolean btreeGameWinningMove(TreeNode root, int n, int x) {
        this.x = x;
        count(root);
        return Math.max(left, Math.max(right, n - left - right - 1)) > n / 2;
    }

    int count(TreeNode root) {
        if (root == null) return 0;
        int l = count(root.left);
        int r = count(root.right);
        if (root.val == x) {
           left = l;
           right = r; 
        }
        return l + r + 1;
    }
}
```