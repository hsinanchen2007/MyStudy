### 解题思路
逆中序，右中左

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
    private int k, res;

    public int kthLargest(TreeNode root, int k) {
        this.k = k;
        reverseOrder(root);
        return res;
    }

    private void reverseOrder(TreeNode node) {
        if (node == null) {
            return;
        }

        reverseOrder(node.right);
        if (--k == 0) {
            res = node.val;
            return;
        }
        reverseOrder(node.left);
    }

}
```