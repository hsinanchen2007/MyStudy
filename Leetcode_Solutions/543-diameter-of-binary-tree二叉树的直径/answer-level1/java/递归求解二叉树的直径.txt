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
    private int path=0;
    public int diameterOfBinaryTree(TreeNode root) {
        int lh=0, rh=0;
        if(root==null)
            return 0;
        if(root.left!=null)
            lh = findPath(root.left)+1;
        if(root.right!=null)
            rh = findPath(root.right)+1;
        return Math.max(lh+rh, path);
    }
    public int findPath(TreeNode root) {
        int lh=0, rh=0;
        if(root.left==null&&root.right==null)
            return 0;
        if(root.left!=null)
            lh = findPath(root.left)+1;
        if(root.right!=null)
            rh = findPath(root.right)+1;
        path=Math.max(path, lh+rh);
        return Math.max(lh, rh);
    }
}
```