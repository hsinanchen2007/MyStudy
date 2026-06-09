### 解题思路
``` java
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0 || inorder.length == 0 || preorder.length != inorder.length) {
            return null;
        }
        return construct(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode construct(int[] preorder, int ps, int pe, int[] inorder, int is, int ie) {
        //如果开始位置大于结束位置，则说明遍历完毕
        if (ps > pe || is > ie) {
            return null;
        }
        //先序遍历序列第一个元素为二叉树的根节点
        int value = preorder[ps];
        //定义一个变量记录遍历的位置
        int index = is;
        while (index <= ie && inorder[index] != value) {
            index++;
        }
        TreeNode node = new TreeNode(value);
        node.left = construct(preorder, ps + 1, pe + index - is, inorder, is, index - 1);
        node.right = construct(preorder, ps + index - is + 1, pe, inorder, index + 1, ie);
        return node;
    }
}
```
