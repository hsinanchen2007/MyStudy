### 解题思路
直接递归交换左右孩子即可；

### 代码

```csharp
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
    public TreeNode MirrorTree(TreeNode root) {
        if (root == null) return null;
        var left = MirrorTree(root.left);
        var right = MirrorTree(root.right);
        root.left = right;
        root.right = left;
        return root;
    }
}
```