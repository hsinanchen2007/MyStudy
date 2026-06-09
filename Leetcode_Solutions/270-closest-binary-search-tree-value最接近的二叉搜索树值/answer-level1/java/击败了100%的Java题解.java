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
    public int closestValue(TreeNode root, double target) {
        if (root == null) {
            return 0;
        }
        int closestValue = root.val;
        while (root != null) {
          if (Math.abs(root.val - target) < Math.abs(closestValue - target)) {
              closestValue = root.val;
          }    
          if (target > root.val) {
              root = root.right;   
          } else if (target < root.val) {
             root = root.left;
          } else {
              return root.val;
          }       
        }
        return closestValue;

    }
}
```