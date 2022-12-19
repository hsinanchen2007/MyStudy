### 解题思路
此处撰写解题思路

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
    public bool IsSymmetric(TreeNode root) {
        
        if(root == null){
            return true;
        }

        TreeNode left = root.left;
        TreeNode right = root.right;
        return IsMirror(left,right);
        
    }

    public bool IsMirror(TreeNode node1,TreeNode node2) {
        if(node1 == null && node2 == null) return true;
        if(node1 == null || node2 == null) return false;
        if(node1.val == node2.val) {
            return IsMirror(node1.left,node2.right) && IsMirror(node1.right,node2.left);
        }else{
            return false;
        }

    }
}
```