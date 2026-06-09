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
        if(root == null) return true;
        return IsSym(root.left,root.right);

    }
    public bool IsSym(TreeNode left,TreeNode right)
    {
        if(left == null && right == null) return true;
        else if(left == null || right == null) return false;
        else if(left.val != right.val) return false;
        return IsSym(left.left,right.right)&&IsSym(left.right,right.left);
    }
}
```