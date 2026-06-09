```java
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return solve(preorder, inorder, 0, 0, preorder.length-1);
    }
    public TreeNode solve(int[] preorder, int[] inorder, int start, int l, int r) {
        if (start >= preorder.length)
            return null;
        TreeNode root = new TreeNode(preorder[start]);
        for (int i = l; i <= r; i++) {
            if (inorder[i] == preorder[start]) {
                if (i != l) {
                    root.left = solve(preorder, inorder, start+1, l, i-1);
                }
                if (i != r) {
                    root.right = solve(preorder, inorder, start+i-l+1, i+1, r);
                }
                break;
            }
        }
        return root;
    }
}
```
思路：从中序遍历中找到根节点，之后缩小遍历范围，下一层的根可以根据当前根在中序中和前序中的位置来确定