### 解题思路
    /*
     * 递归法
     *
     * 二叉树的深度即从二叉树根节点到子节点最长路径的长度，
     * 如果二叉树只有一个根节点，则深度为1；
     * 如果根节点只有左子树，则左子树的深度加1；
     * 如果根节点只有右子树，则右子树的深度加1；
     * 如果根节点有左右子树，则选择左右子树中深度较大的加1。
     * 二叉树的深度通过递归遍历取得，当递归到叶子节点后，
     * 递归栈开始弹出，每弹出一个节点，则深度加1。
     * */
### 代码

```cpp
int maxDepth(BiTreeNode *root) {
    if(root == nullptr){
        return 0;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 返回左右子树深度较大的值加1
    return std::max(leftDepth, rightDepth) + 1;

    // 将上述三步总结为一句返回
//    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

```