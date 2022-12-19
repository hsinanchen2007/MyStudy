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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null)
            return true;
        else if (p == null || q == null)
            return false;
        boolean ans = p.val == q.val;
        ans = (ans && isSameTree(p.left, q.left));
        ans = (ans && isSameTree(p.right, q.right));
        return ans;
    }
}
```
写这种题就是爽