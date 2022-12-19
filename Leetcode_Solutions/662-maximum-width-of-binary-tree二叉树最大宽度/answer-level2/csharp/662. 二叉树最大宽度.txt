### 解题思路
递归 记录每个节点的序号，孩子的序号等于父节点序号*2

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
    public int WidthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        var maxWidth = 1;
        var currentLevel = new Dictionary<TreeNode, int>();
        currentLevel.Add(root, 1);
        while (currentLevel.Count > 0)
        {
            (int left, int right) level = (int.MaxValue, int.MinValue);
            var nextLevel = new Dictionary<TreeNode, int>();
            foreach (var node in currentLevel.Keys)
            {
                var index = currentLevel[node];
                level.left = Math.Min(level.left, index);
                level.right = Math.Max(level.right, index);
                if (node.left != null)
                    nextLevel.Add(node.left, index * 2 - 1);
                if (node.right != null)
                    nextLevel.Add(node.right, index * 2);
            }
            maxWidth = Math.Max(maxWidth, level.right - level.left + 1);
            currentLevel = nextLevel;
        }
        return maxWidth;
    }
}
```