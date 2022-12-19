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
    public int diameterOfBinaryTree(TreeNode root) {
        if(root == null) return 0; 
        int ans1 = depth(root.left) + depth(root.right);
        int ans2 = Math.max(diameterOfBinaryTree(root.left),diameterOfBinaryTree(root.right));
        return Math.max(ans1,ans2);
    }
    public int depth(TreeNode root) {
        if(root == null) return 0;
        return 1 + Math.max(depth(root.left),depth(root.right));
    }
}
```