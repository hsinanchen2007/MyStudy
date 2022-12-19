```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null
            || preorder.length == 0 || inorder.length == 0
            || preorder.length != inorder.length)
            return null;
        return dfs(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode dfs(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return null;
        // start with root node
        TreeNode node = new TreeNode(preorder[preStart]);
        // index to distribute inorder array to 2 parts
        int index = 0;
        while(preorder[preStart] != inorder[inStart + index])
            index++;
        node.left = dfs(preorder, preStart + 1, preStart + index, inorder, inStart, inStart + index - 1);
        node.right = dfs(preorder, preStart + index + 1, preEnd, inorder, inStart + index + 1, inEnd);
        return node;
    }
}
```