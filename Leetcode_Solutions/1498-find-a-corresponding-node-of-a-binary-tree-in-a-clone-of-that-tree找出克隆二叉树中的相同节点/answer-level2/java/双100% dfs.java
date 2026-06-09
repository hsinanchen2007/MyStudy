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
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) {
        if (original == null)
            return null;
        if (original == target)
            return cloned;
        else{
            TreeNode left = getTargetCopy(original.left, cloned.left, target);
            if (left != null)
                return left;
            TreeNode right = getTargetCopy(original.right, cloned.right, target);
            if (right != null)
                return right;
        }
        return null;
    }
}
```