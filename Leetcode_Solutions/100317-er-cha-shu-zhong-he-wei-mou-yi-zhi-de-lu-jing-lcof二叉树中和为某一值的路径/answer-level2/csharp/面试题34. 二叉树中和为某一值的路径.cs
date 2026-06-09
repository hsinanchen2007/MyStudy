### 解题思路
回溯法
需要注意的问题：
1. 数值不一定全是正数，有可能会是负数
2. 路径要求必须是根节点到叶子结点
3. 回溯时，Path.Add()必须要有对应的Path.RemoveAt(Path.Length-1)

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
    public IList<IList<int>> PathSum(TreeNode root, int sum) 
    {
        if (root == null) return new List<IList<int>>();
        var path = new List<int>();
        var results = new List<IList<int>>();
        PathSum(root, sum, ref path, 0, ref results);
        return results;
    }

    public static void PathSum(TreeNode root, int sum, ref List<int> path, int currentSum, ref List<IList<int>> results)
    {
        currentSum += root.val;

        path.Add(root.val);
        // 要求路径必须到叶子结点
        if (root.left == null && root.right == null)
        {
            if (currentSum == sum)
            {
                results.Add(new List<int>(path));
            }
        }
        else
        {
            if (root.left != null)
            {
                PathSum(root.left, sum, ref path, currentSum, ref results);
            }
            if (root.right != null)
            {
                PathSum(root.right, sum, ref path, currentSum, ref results);
            }
        }
        path.RemoveAt(path.Count - 1);
    }
}
```