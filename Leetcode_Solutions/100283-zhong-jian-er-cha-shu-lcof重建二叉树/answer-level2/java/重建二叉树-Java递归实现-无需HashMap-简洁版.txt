```
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
        if (preorder.length == 0) return null;
        if (preorder.length == 1) return new TreeNode(preorder[0]);
        
        int[] leftPre, leftIn, rightPre, rightIn;
        int leftSize = 0;
        int rightSize = 0;
        for (int i = 0; i < inorder.length; i++) {
            if (inorder[i] == preorder[0]) {
                leftSize = i;
                rightSize = inorder.length - 1 - leftSize;
                break;
            }
        }
        leftPre = Arrays.copyOfRange(preorder, 1, 1 + leftSize);
        leftIn = Arrays.copyOfRange(inorder, 0, leftSize);
        rightPre = Arrays.copyOfRange(preorder, 1 + leftSize, preorder.length);
        rightIn = Arrays.copyOfRange(inorder, leftSize + 1, inorder.length);

        TreeNode root = new TreeNode(preorder[0]);
        root.left = buildTree(leftPre, leftIn);
        root.right = buildTree(rightPre, rightIn);

        return root;
    }
}
```
