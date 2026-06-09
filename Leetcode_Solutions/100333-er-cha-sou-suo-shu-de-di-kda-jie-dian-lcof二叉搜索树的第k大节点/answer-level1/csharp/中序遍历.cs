### 解题思路
由于二叉搜索树的中序遍历是有序的，所有先通过中序遍历得到有序的数组，然后再取出第K大的元素。

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
    public int KthLargest(TreeNode root, int k) {
        if(root == null || k < 0)
        {
            return -1;
        }
        List<int> list = new List<int>();
        Helper(root, list);
        return list[list.Count - k];
    }

    private void Helper(TreeNode root, List<int> list)
    {
        if(root == null)
        {
            return;
        }
        Helper(root.left, list);
        list.Add(root.val);
        Helper(root.right, list);
    }
}
```