### 解题思路


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
    public int maxDepth(TreeNode root) {
        if(root == null) return 0;
        else{
            //分别递归得到结点的左子树与右子树深度
            int left_height = maxDepth(root.left);
            int right_height = maxDepth(root.right);
            //获得该结点的最大深度
            int max_height = Math.max(left_height,right_height)+1;
            return max_height;

        }
    }
}
```