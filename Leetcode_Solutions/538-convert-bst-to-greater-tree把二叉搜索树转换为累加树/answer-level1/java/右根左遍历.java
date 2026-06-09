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
    int sum = 0;
    public TreeNode convertBST(TreeNode root) {
        travel(root);
        return root;
    }

    void travel(TreeNode root) {
        if (root == null) {
            return;
        }
        travel(root.right);
        sum +=root.val;
        root.val = sum;
        travel(root.left);
    }
}
```