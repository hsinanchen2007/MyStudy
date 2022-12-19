
class Solution {

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || preorder.length == 0) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[0]);
        int index = 0;
        for (;index < inorder.length; index++) {
            if (inorder[index] == preorder[0]) {
                break;
            }
        }

        //左子树的前序遍历、中序遍历 右子树的前序遍历、中序遍历
        int[] newLeftInOrder = Arrays.copyOfRange(inorder, 0, index);
        int[] newRightInOrder = Arrays.copyOfRange(inorder, index + 1, inorder.length);
        int[] newLeftPreOrder = Arrays.copyOfRange(preorder, 1, index + 1);
        int[] newRightPreOrder = Arrays.copyOfRange(preorder, index + 1, preorder.length);
        root.left = buildTree(newLeftPreOrder, newLeftInOrder);
        root.right = buildTree(newRightPreOrder, newRightInOrder);
        return root;
    }
}