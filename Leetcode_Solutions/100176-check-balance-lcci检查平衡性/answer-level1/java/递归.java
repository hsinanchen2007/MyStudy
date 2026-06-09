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
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        return  dfs(root) != -1;
    }

    private int dfs(TreeNode root) {
      if(root == null){
            return 0;
        }else {
            int leftH = root.left == null ? 0 : dfs(root.left);
            if(leftH == -1) return -1;
            int rightH = root.right == null ? 0 : dfs(root.right);
            if(rightH == -1) return -1;
            return Math.abs(leftH - rightH) > 1 ? -1 : Math.max(rightH,leftH) + 1;
        }
    }
}
```