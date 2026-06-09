
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
    private int count = 0;
    private int val = -1;
    public int kthLargest(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }
        count = k;
        func(root);
        return val;
    }

    void func(TreeNode root) {
        if (root == null) {
            return;
        }
        func(root.right);
        count--; // 一定是先减小！如果先判断=1，则会导致count没有变化，返回到上一层依旧满足=1的条件
        if (count == 0) {
            val = root.val;
            return;
        }
        func(root.left);
    }
}
```