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
    public TreeNode invertTree(TreeNode root) {
        if(root==null) return root;
        if(root.left==null && root.right==null) return root;
        if(root.left!=null || root.right!=null) {
            TreeNode temp = root.left;
            root.left = root.right;
            root.right = temp;
        }
        if(root.left!=null) invertTree(root.left);
        if(root.right!=null) invertTree(root.right);
        return root;
    }

    
}
```
速度还可以，内存消耗有些大，应该可以优化