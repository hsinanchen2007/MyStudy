### 解题思路
没找到像python一样一句交换的
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
    public TreeNode InvertTree(TreeNode root) {
        if(root==null) return null;
           var tmp = root.left;
            root.left = root.right;
            root.right = tmp;
            InvertTree(root.right);
            InvertTree(root.left);
            return root;
    }
}
```