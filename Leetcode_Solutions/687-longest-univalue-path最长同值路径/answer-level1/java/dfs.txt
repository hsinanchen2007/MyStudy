### 解题思路
    travel方法的返回值表示该节点的左（或右子树）连续相同值的个数
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
    public int longestUnivaluePath(TreeNode root) {
        travel(root);
        return max;
    }

    int travel(TreeNode root) {
        if (root == null) {
            return 0;
        }

        int l = travel(root.left);
        int r = travel(root.right);

        int lcur = -1;
        int rcur = -1;
        int cur =  1;

        if (root.left != null && root.val == root.left.val) {
            lcur = l;
            cur +=l;
        }

        if (root.right != null && root.val == root.right.val) {
            rcur = r;
            cur+=r;
        }
        max = Math.max(cur-1, max);

        if (lcur == -1 && rcur == -1) {
            return 1;
        }

        if (lcur != -1 && rcur == -1) {
            return lcur + 1;
        }

        if (lcur == -1 && rcur != -1) {
            return rcur + 1;
        }

        return Math.max(l, r) + 1;
    }
}
```