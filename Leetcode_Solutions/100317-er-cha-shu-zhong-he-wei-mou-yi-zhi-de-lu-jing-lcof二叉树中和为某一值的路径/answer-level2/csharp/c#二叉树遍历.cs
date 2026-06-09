### 解题思路
二叉树遍历
遍历过程中用sum - 节点的val，并用list记录val
当sum == 0而且是叶子时记录整个list到results里
注意遍厉完子点结后sum += 节点的val
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
    List<IList<int>> results = new List<IList<int>>();

    public IList<IList<int>> PathSum(TreeNode root, int sum) {
        List<int> tempList = new List<int>();
        SearchTree(root, sum, tempList);
        return results;
    }

    void SearchTree(TreeNode root, int sum, List<int> numList)
    {
        if(root == null)
        {
            return;
        }

        numList.Add(root.val);
        sum -= root.val;

        if(sum == 0 && root.left == null && root.right == null)
        {
            results.Add(new List<int>(numList));
        }

        SearchTree(root.left, sum, numList);
        SearchTree(root.right, sum, numList);

        sum += root.val;
        numList.RemoveAt(numList.Count - 1);
    }
}
```