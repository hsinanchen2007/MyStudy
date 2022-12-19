### 解题思路
最大路径一定包含至少1个节点

a
b   c
d e f g

对节点c而言
{
    如果c是最终路径的顶部节点
        max = max(c+leftmax, c+rightmax, c+leftmax+rightmax,c);
    如果c不是最终路径的顶部节点
        需要返回一个包含c的最大路径给上层节点用，即max(c+leftmax, c+rightmax,c)
}
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

    int max;
    public int MaxPathSum(TreeNode root) {
        max = int.MinValue;
        MaxPathIncludeRoot(root);
        return max;        
    }

    public int MaxPathIncludeRoot(TreeNode root)
    {
        var currentmax = root.val;
        var leftmax = int.MinValue;
        var rightmax = int.MinValue;
        if(root.left != null)
        {
            leftmax = MaxPathIncludeRoot(root.left);
            currentmax += leftmax > 0 ? leftmax : 0;
        }
       if(root.right != null)     
        {
            rightmax = MaxPathIncludeRoot(root.right);
            currentmax += rightmax > 0 ? rightmax : 0;
        }
        max = Math.Max(max, currentmax);
        return root.val + Math.Max(0,Math.Max(leftmax, rightmax));
    }
}
```