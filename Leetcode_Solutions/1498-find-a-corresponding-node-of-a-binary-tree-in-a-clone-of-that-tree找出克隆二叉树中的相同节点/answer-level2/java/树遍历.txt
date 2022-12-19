### 解题思路
前序DFS遍历

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
         if(original == null) {
            return null;
         } 
         if(original == target) {
             return cloned;
         }
         TreeNode les = getTargetCopy(original.left, cloned.left, target);
         if(les != null) {
             return les;
         }
         TreeNode res = getTargetCopy(original.right, cloned.right, target);
         if(res != null) {
             return res;
         }
         return null;
    }
}
```