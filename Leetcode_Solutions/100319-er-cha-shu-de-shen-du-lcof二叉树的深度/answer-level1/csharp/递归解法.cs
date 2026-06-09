### 递归
深度优先遍历计算最大深度

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
    public int MaxDepth(TreeNode root) {
        return MaxDepth(root, 0);
    }

    private int MaxDepth(TreeNode root, int currentDepth)
    {
        if(root == null)
        {
            return currentDepth;
        }

        return Math.Max(MaxDepth(root.left, currentDepth + 1), MaxDepth(root.right, currentDepth + 1));
    }
}
```