### 解题思路
递归

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
    public void Flatten(TreeNode root) {
       if(root == null)
       {
           return;
       }
       Flatten(root.left);
       Flatten(root.right);
       var temp = root.right;
       root.right = root.left;
       //这一步置left为空不能忘
       root.left = null;
       while(root.right != null)
       {
           root = root.right;
       }
       root.right = temp;
    }


}
```