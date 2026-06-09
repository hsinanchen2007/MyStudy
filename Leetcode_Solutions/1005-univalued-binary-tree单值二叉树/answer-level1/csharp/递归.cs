### 解题思路
递归
1.确认是否可以拆分成子问题求解
2.找到终止条件

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
    public bool IsUnivalTree(TreeNode root)
        {
            if (root == null)
            {
                return true;
            }

            int target = root.val;
            return IsUnivalTree(root.left, target) && IsUnivalTree(root.right, target);
        }

        private bool IsUnivalTree(TreeNode root, int target)
        {
            if (root == null)
            {
                return true;
            }
            if (root.val != target)
            {
                return false;
            }

            return IsUnivalTree(root.left, target) && IsUnivalTree(root.right, target);
        }
}
```