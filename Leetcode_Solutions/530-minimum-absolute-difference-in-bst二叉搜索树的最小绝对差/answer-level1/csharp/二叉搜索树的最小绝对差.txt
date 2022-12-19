### 解题思路
1. 递归获取所有的节点
2. 计算出最小差值

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
     public int GetMinimumDifference(TreeNode root)
        {
            List<int> nodeValue = new List<int>();
            GetNodeValueList(root, nodeValue);
            var orderedList = nodeValue.OrderBy(t => t).ToList();
            int result = int.MaxValue;
            for (int i = 1; i < orderedList.Count; i++)
            {
                result = Math.Min(result, orderedList[i] - orderedList[i-1]);
            }

            return result;
        }

        private void GetNodeValueList(TreeNode root, List<int> nodeValue)
        {
            if (root == null)
            {
                return;
            }
            nodeValue.Add(root.val);
            GetNodeValueList(root.left, nodeValue);
            GetNodeValueList(root.right, nodeValue);
        }
}
```