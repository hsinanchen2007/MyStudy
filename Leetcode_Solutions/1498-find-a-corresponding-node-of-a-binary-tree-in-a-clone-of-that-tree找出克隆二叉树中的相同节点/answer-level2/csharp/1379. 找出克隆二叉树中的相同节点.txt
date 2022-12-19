### 解题思路
就是简单的递归遍历二叉树

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
    public TreeNode GetTargetCopy(TreeNode original, TreeNode cloned, TreeNode target) {
        if(original==null)
            return null;
        if(original.val == target.val)
            return cloned;
        var left = GetTargetCopy(original.left,cloned.left,target);
        if(left!=null)
            return left;
        var right = GetTargetCopy(original.right,cloned.right,target);
        if(right!=null)
            return right;
        return null;
    }
}
```