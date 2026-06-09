### 解题思路
基础递归的思路详见官方题解方法一，由于是判断节点值和左右子节点的true数量和（即下文），因此所求节点的父节点不会被认为是答案。
```csharp
if ((left + right + mid) >= 2)
            res = head;
```
然而这个方法有个问题是假设res = root.left，那么右子树下的每个节点还是会因为递归被判断一遍，时间复杂度一定是O(n)。为了剪枝在递归的部分增加了一个小的判断，当res已经被找到的时候，其他子树顶端直接给false。优化后的时间复杂度最差是O(n)。
```csharp
if(res != null || head == null)
    return false;
```

执行用时 :120 ms, 在所有 C# 提交中击败了91.67%的用户

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

    public TreeNode res;
    public TreeNode LowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            IsAncestor(root, p, q);
            return res;        
    }

    public bool IsAncestor(TreeNode head, TreeNode p, TreeNode q)
    {
        if(res != null || head == null)
            return false;

        var left = IsAncestor(head.left, p, q) == true ? 1 : 0;
        var right = IsAncestor(head.right, p, q) == true ? 1 : 0;
        var mid = (head == p || head == q) ? 1 : 0;
        if ((left + right + mid) >= 2)
            res = head;
        return (left + right + mid) > 0;
    }
}
```