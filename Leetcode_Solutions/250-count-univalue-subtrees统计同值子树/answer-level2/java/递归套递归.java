外层递归遍历所有节点，内层递归判断是否为同值子树

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
    public int res = 0;
    public int countUnivalSubtrees(TreeNode root) {
        if (root == null) {
            return 0;
        }
        count(root);
        return res;
    }
    public void count(TreeNode root) {
        if (root == null) {
            return;
        }
        if (isSame(root, root.val)) {
            res++;
        }
        count(root.left);
        count(root.right);
    }
    public boolean isSame(TreeNode root, int val) {
        if (root == null) {
            return true;
        }
        if (root.val == val) {
            return isSame(root.left, val) && isSame(root.right, val);
        }
        return false;
    }
}
```