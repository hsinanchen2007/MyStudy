### 解题思路
分别获取两个树的子序列，然后进行进行对比即可。

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
    public bool LeafSimilar(TreeNode root1, TreeNode root2)
        {
            List<int> leafs1 = new List<int>();
            List<int> leafs2 = new List<int>();
            GetLeafs(root1, leafs1);
            GetLeafs(root2, leafs2);

            if (leafs1.Count != leafs2.Count)
            {
                return false;
            }
            for (int i = 0; i < leafs1.Count; i++)
            {
                if (leafs1[i] != leafs2[i])
                {
                    return false;
                }
            }

            return true;
        }

        private void GetLeafs(TreeNode root, List<int> list)
        {
            if (root == null)
            {
                return;
            }
            if (root.left == null && root.right == null)
            {
                list.Add(root.val);
            }
            GetLeafs(root.left, list);
            GetLeafs(root.right, list);
        }
}
```