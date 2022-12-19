### 解题思路
找到规律递归即可

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
    public TreeNode BuildTree(int[] preorder, int[] inorder) {
        if(preorder == null || inorder == null || preorder.Length != inorder.Length || preorder.Length == 0)
        {
            return null;
        }
        
        return Helper(preorder, 0, preorder.Length - 1, inorder, 0, inorder.Length - 1);
    }

    private TreeNode Helper(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd)
    {
        if(preStart > preEnd)
        {
            return null;
        }

        var root = new TreeNode (preorder[preStart]);
        int index = inStart;
        for(;index <= inEnd; index++)
        {
            if(inorder[index] == preorder[preStart])
            {
                break;
            }
        }
        root.left = Helper(preorder, preStart + 1, preStart + index - inStart, inorder, inStart, index - 1);
        root.right = Helper(preorder, preStart + index - inStart + 1, preEnd, inorder, index + 1, inEnd);

        return root;
    }
}
```