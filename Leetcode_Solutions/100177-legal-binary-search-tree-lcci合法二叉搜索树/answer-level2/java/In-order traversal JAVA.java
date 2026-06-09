### 解题思路
Assume the tree has no duplicate value...

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
    // In-order traversal
    // used an Integer instead of int so that we can know when last_printed has been set to a value
    Integer last_printed = null;
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (!isValidBST(root.left)) {
            return false;
        }
        // has to be strictly larger than previous value
        if (last_printed != null && root.val <= last_printed) {
            return false;
        }
        last_printed = root.val;
        if(!isValidBST(root.right)) {
            return false;
        }
        return true;
    }
}
```