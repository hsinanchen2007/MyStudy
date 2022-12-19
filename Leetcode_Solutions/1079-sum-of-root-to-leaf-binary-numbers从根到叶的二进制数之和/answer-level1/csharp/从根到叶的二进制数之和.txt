### 解题思路
结合257题获取所有路径进行求解。

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
    public int SumRootToLeaf(TreeNode root)
        {
            int result = 0;
            var binaryStrings = BinaryTreePaths(root);
            foreach(var item in binaryStrings)
            {
                result += GetValueByString(item);
            }

            return result;
        }

        private int GetValueByString(string item)
        {
            int result = 0;
            for (int i = item.Length - 1; i >= 0; i--)
            {
                result += int.Parse(item[i].ToString()) * (int)Math.Pow(2, item.Length - i -1);
            }

            return result;
        }

        private IList<string> BinaryTreePaths(TreeNode root)
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
                    result.Add(root.val.ToString() + item);
                }
            }
            if (root.right != null)
            {
                var list = BinaryTreePaths(root.right);
                foreach (var item in list)
                {
                    result.Add(root.val.ToString() + item);
                }
            }

            return result;
        }
}
```