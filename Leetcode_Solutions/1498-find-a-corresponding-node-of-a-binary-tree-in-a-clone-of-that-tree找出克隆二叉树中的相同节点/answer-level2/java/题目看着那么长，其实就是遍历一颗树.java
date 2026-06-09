### 解题思路
直接看代码

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
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if(cloned != null) {
            if(cloned.val == target.val) {
                return cloned;
            }
            TreeNode left = getTargetCopy(original, cloned.left, target);
            if(left == null) {
                return getTargetCopy(original, cloned.right, target);
            } else {
                return left;
            }
        }
        return null;
        
    }
}
```