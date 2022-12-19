### 解题思路
此处撰写解题思路

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
    static int sum;

    public int sumOfLeftLeaves(TreeNode root) {
        sum = 0;
        reCur(root);
        return sum;

    }

    public static void reCur(TreeNode p) {
        if (p == null)
            return;

        if (p.left != null && p.left.left == null && p.left.right == null)
            sum += p.left.val;

        reCur(p.left);
        reCur(p.right);

        return;
    }
}
```