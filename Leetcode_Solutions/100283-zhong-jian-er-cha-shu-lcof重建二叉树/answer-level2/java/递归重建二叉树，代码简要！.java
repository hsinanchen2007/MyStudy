先上源代码康康：

```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }

    private TreeNode buildTree(int[] preorder, int preStart, int preEnd
                            , int[] inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return null;
        }
        
        TreeNode root = new TreeNode(preorder[preStart]);
        
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == preorder[preStart]) {
                root.left = buildTree(preorder, preStart + 1, i - inStart + preStart
                                    , inorder, inStart, i - 1);
                root.right = buildTree(preorder, i - inStart + preStart + 1, preEnd
                                    , inorder, i + 1, inEnd);
            }
        }
        return root;
    }
}
```

注解版：

```
class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1);
    }
    
    /**
     * preStart - preEnd 代表了在 preorder[] 中查找的区间范围
     * inStart - inEnd   代表了在 inorder[]  中查找的区间范围
     */
    private TreeNode buildTree(int[] preorder, int preStart, int preEnd
                            , int[] inorder, int inStart, int inEnd) {
        // 显而易见的结束条件
        if (preStart > preEnd || inStart > inEnd) {
            return null;
        }
        // 前序遍历的第一个节点为 root
        TreeNode root = new TreeNode(preorder[preStart]);
        
        // 在中序遍历的查找区间中找到 root 所处位置
        for (int i = inStart; i <= inEnd; i++) {

            if (inorder[i] == preorder[preStart]) {
                // 前序区间的 start 从根节点后一位开始
                // 前序区间的 end 是中序遍历确定的左子树节点个数 + 原先的preStart
                // 中序区间的 start 不变，因为从头开始找左子树
                // 中序区间的 end 最多达到当前根节点的前一位
                root.left = buildTree(preorder, preStart + 1, i - inStart + preStart
                                    , inorder, inStart, i - 1);

                // 前序区间的 start 从当前根节点跳过左子树个数开始
                // 前序区间的 end 保持不变，扫描到底
                // 中序区间的 start 从根节点的后一位开始
                // 中序区间的 end 保持不变
                root.right = buildTree(preorder, i - inStart + preStart + 1, preEnd
                                    , inorder, i + 1, inEnd);
            }
        }
        return root;
    }
}
```
