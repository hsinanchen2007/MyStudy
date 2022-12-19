### 解题思路
    /*
     * 递归更新最大值
     *
     * 如果路径必须经过二叉树的根节点，
     * 则直径的最大长度就是左右子树的深度和。
     * 但此处是二叉树中的任意两个节点，
     * 二叉树任意两个节点之间的路径必然经过某一节点，
     * 该节点是路径两端节点的父节点或祖先节点，
     * 那么以该节点为根节点，路径的长度即根节点左右子树深度的和。
     * 由此可以想到，只要以二叉树任意节点为根节点，
     * 计算该根节点左右子树的和，同时每次更新它们为最大的值，
     * 最后得到的结果就是二叉树两节点间的最长直径。
     * */
### 代码

```cpp
int diameter = 0;
int diameterOfBinaryTree(TreeNode *root) {
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }

    depth(root);

    return diameter;
}

int depth(TreeNode *root) {
    if(root == nullptr){
        return 0;
    }

    // 左子树的深度
    int leftDepth = depth(root->left);
    // 右子树的深度
    int rightDepth = depth(root->right);

    // 更新直径的最大值
    // 二叉树的最大直径是：
    // 以任意一个节点为根节点，
    // 求其左右子树的深度leftDepth和rightDepth，
    // 最大直径为左右子树深度的和
    diameter = std::max(diameter, leftDepth+rightDepth);

    // 返回左右子树中深度较大的值加1
    return std::max(leftDepth, rightDepth) + 1;
}
```