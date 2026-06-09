### 解题思路
就是需要多考虑一种特殊情况：只有左/右子树

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
    public int minDepth(TreeNode root) {

        if (root == null){
            return 0;
        }

        if(root.left == null && root.right == null){
            return 1;
        }
        if(root.left == null || root.right == null){
            return 1 + Math.max(minDepth(root.left), minDepth(root.right));
        }
        return 1 + Math.min(minDepth(root.left), minDepth(root.right));
    }

   
}
```