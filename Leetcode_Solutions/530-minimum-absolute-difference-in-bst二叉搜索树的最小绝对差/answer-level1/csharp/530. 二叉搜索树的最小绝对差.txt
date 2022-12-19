### 解题思路
C# 中序遍历树为排序数组 临近比较

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
    public int GetMinimumDifference(TreeNode root) {
        var list = new List<int>();
        TreeToList(root, ref list);
        int minDiff = int.MaxValue;
        for (int index = 1; index < list.Count; index++)
        {
            minDiff = Math.Min(minDiff, list[index] - list[index - 1]);
        }
        return minDiff;
    }

    public void TreeToList(TreeNode root, ref List<int> list)
    {
        if (root == null) return;
        TreeToList(root.left, ref list);
        list.Add(root.val);
        TreeToList(root.right, ref list);
    }
}
```