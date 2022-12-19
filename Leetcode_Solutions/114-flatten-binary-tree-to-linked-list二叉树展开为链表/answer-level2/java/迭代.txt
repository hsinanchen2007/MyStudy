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
    public void flatten(TreeNode root) {
        if(root == null) return;

        while(root != null) {
            if(root.left != null) helper(root);
            root = root.right;
        }
    }

    private void helper(TreeNode root) {
        TreeNode tempR = root.right;
        TreeNode tempL = root.left;

        root.right = root.left;
        root.left = null;

        while(tempL.right != null)
            tempL = tempL.right;
        
        tempL.right = tempR;
    }
}
```