### 解题思路
二叉树刷下来大多递归，拿到题目先看是否可以拆分成子问题进行求解。

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
    public IList<string> BinaryTreePaths(TreeNode root)
        {
            List<string> result = new List<string>();
            if (root == null)
            {
                return result;
            }
            if (root.left == null && root.right == null)
            {
                result.Add(root.val.ToString());
                return result;
            }
            if (root.left != null)
            {
                var list = BinaryTreePaths(root.left);
                foreach (var item in list)
                {
                    result.Add(root.val + "->" + item);
                }
            }
            if (root.right != null)
            {
                var list = BinaryTreePaths(root.right);
                foreach (var item in list)
                {
                    result.Add(root.val + "->" + item);
                }
            }

            return result;
        }
}
```