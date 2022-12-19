### 解题思路
递归
1. 确认该问题是否能够通过子问题得出父问题的解
2. 找到递归终止的条件就可以写代码了

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
   public TreeNode TrimBST(TreeNode root, int L, int R)
        {
            if (root == null)
            {
                return null;
            }
            else if (root.val == L)
            {
                root.left = null;
                root.right = TrimBST(root.right, L, R);
                return root;
            }
            else if (root.val < L)
            {
                return TrimBST(root.right, L, R);
            }
            else if (root.val == R)
            {
                root.right = null;
                root.left = TrimBST(root.left, L, R);
                return root;
            }
            else if (root.val >= R)
            {
                return TrimBST(root.left, L, R);
            }
            else
            {
                root.left = TrimBST(root.left, L, R);
                root.right = TrimBST(root.right, L, R);
                return root;
            }
        }
}
```