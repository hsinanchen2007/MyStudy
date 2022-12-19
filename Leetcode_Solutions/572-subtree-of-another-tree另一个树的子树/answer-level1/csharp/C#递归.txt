### 解题思路
递归

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
    public bool IsSubtree(TreeNode s, TreeNode t)
        {

            if (s == null && t == null)
            {
                return true;
            }
            else if (s == null || t == null)
            {
                return false;
            }
            else if (s.val == t.val)
            {
                return (IsSameTree(s, t)) || IsSubtree(s.left, t) || IsSubtree(s.right, t);
            }
            else
            {
                return IsSubtree(s.left, t) || IsSubtree(s.right, t);
            }
        }

        private bool IsSameTree(TreeNode root1, TreeNode root2)
        {
            if (root1 == null && root2 == null)
            {
                return true;
            }
            else if (root2 == null || root1 == null)
            {
                return false;
            }
            else if (root1.val != root2.val)
            {
                return false;
            }
            return IsSameTree(root1.left, root2.left) && IsSameTree(root1.right, root2.right);

        }
}
```