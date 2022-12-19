### 解题思路
此处撰写解题思路

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
    public bool IsSymmetric(TreeNode root) {
        if (root == null)
        {
            return true;
        }
        return Check(root.left, root.right);
    }

    public bool Check(TreeNode left, TreeNode right)
    {
        if (left == null && right == null)
        {
            return true;
        }
        if (left != null && right != null && left.val == right.val)
        {
            return Check(left.left, right.right) && Check(left.right, right.left);
        }
        return false;
    }
}
```