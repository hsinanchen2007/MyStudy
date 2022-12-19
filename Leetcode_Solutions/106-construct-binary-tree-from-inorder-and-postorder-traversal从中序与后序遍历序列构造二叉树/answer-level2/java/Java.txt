1.使用左右都是闭区间的解法。
2.其中最难理解的应该是左子树和右子树递归时的下标的取值，建议可以先画个三层的完整二叉树，分别写出其对应的中序列遍历和后序遍历，然后对应着看就很清晰了。
```
class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return dfs(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1);
    }

    private TreeNode dfs(int[] inorder, int iStart, int iEnd, int[] postorder, int pStart, int pEnd) {
        if (iStart > iEnd || pStart > pEnd) {
            return null;
        }
        TreeNode root = new TreeNode(postorder[pEnd]);
        int index = 0;
        while (inorder[iStart + index] != postorder[pEnd]) {
            index++;
        }
        root.left = dfs(inorder, iStart, iStart + index - 1, postorder, pStart, pStart + index - 1);
        root.right = dfs(inorder, iStart + index + 1, iEnd, postorder, pStart + index, pEnd - 1);
        return root;
    }
}
```
