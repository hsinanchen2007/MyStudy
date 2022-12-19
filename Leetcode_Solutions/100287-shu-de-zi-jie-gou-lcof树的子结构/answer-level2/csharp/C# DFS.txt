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
    public bool IsSubStructure(TreeNode A, TreeNode B) {
        if(A == null || B == null) return false;
        return IsSubTree(A,B) || IsSubStructure(A.left,B) || IsSubStructure(A.right,B);
    }

    private bool IsSubTree(TreeNode a, TreeNode b)
    {
        if(b == null)return true;
        if( a == null ) return false;
        if( a.val != b.val) return false;
        return IsSubTree(a.left,b.left) && IsSubTree(a.right,b.right);
    }
}
```