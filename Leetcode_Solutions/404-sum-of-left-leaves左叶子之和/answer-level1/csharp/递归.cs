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
   private int result = 0;
        public int SumOfLeftLeaves(TreeNode root)
        {
            
            if (root == null)
            {
                return result;
            }

            GetSum(root.left, true);
            GetSum(root.right, false);

            return result;
        }

        private void GetSum(TreeNode root, bool isFromLeft)
        {
            if (root == null)
            {
                return;
            }
            if (root.left == null && root.right == null)
            {
                if (isFromLeft)
                {
                    result += root.val;
                }
                return;
            }
            if (root.left != null)
            {
                GetSum(root.left, true);
            }
            if (root.right != null)
            {
                GetSum(root.right, false);
            }
        }
}
```