不能像python一样直接`if(!root)`，`if(root==null)`
`root.val`这里比c++方便一些
```
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public bool IsUnivalTree(TreeNode root) {
        if(root==null) return true;
      if(root.left!=null&&root.left.val!=root.val||root.right!=null&&root.right.val!=root.val)return false;
        return IsUnivalTree(root.left)&&IsUnivalTree(root.right);
    }
}
```
