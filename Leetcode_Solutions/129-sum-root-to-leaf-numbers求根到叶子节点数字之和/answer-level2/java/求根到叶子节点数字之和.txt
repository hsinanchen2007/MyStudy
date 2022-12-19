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
    public int sumNumbers(TreeNode root) {
        return sumNumbersCore(root, 0);
    }

    private int sumNumbersCore(TreeNode root, int val) {
        if (root == null) {
            return val;
        }
        
        int newVal = val * 10 + root.val;

        if (root.left == null && root.right == null) {
            return newVal;
        }
        
        int result = 0;
        if (root.left != null) {
            result += sumNumbersCore(root.left, newVal);
        }
        
        if (root.right != null) {
            result += sumNumbersCore(root.right, newVal);
        }

        return result;
    }
}
```