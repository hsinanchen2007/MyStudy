### 解题思路
递归，具体思路见注释。

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
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // 基准情形：遇到空节点返回空，遇到目标节点（与p或q相等）时，返回当前节点
        if(root == null) return null;
        if(root.val == p.val || root.val == q.val)     
        {
            return root;
        }

        // 没有到达基准情形时，会逐层向下递归
        var left= LowestCommonAncestor(root.left,p,q);
        var right = LowestCommonAncestor(root.right,p,q);

        // 递归返回时，对结果进行判断：
        // 如果左边没找到，则返回右节点，否则，返回左结点；
        if(left==null) return right;
        if(right== null) return left;

        // 如果左右都找这到了，说明当前节点就是最近公共祖先
        return root;
    }
}
```