### 解题思路
1. 获取中序遍历的结果
2. 根据中序遍历结果构造出最终结果

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
    public TreeNode IncreasingBST(TreeNode root)
        {
            List<int> list = new List<int>();
            GetList(root, list);

            TreeNode result = new TreeNode(0);
            var tempNode = result;
            for (int i = 0; i < list.Count - 1; i++)
            {
                tempNode.val = list[i];
                tempNode.right = new TreeNode(0);
                tempNode = tempNode.right;
            }
            tempNode.val = list.Last();

            return result;
        }

        private void GetList(TreeNode root, List<int> list)
        {
            if (root == null)
            {
                return;
            }

            GetList(root.left, list);
            list.Add(root.val);
            GetList(root.right, list);
        }
}
```