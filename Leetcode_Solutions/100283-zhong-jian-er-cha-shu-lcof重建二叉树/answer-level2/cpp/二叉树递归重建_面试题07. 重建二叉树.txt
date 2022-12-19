对于树的构建，通常思路就是使用递归方法，效率不高但是很实用！看到题解里面的大神，也通过其他方法对递归进行优化，学到了许多～

    /*
     * 方法1
     * 二叉树前序遍历的第一个数必然是二叉树的根结点，
     * 在中序遍历中找到根结点的位置，
     * 那么中序遍历中根结点位置左边结点即二叉树的左子树结点的中序遍历，
     * 中序遍历根结点位置的右边结点即二叉树的右子树结点的中序遍历；
     * 先计算出左树结点数量c，
     * 则在前序遍历中根结点位置右边的c个结点即二叉树的左子树结点的前序遍历，
     * 前序遍历中剩下的结点即二叉树的右子树结点的前序遍历；
     * 根据数量c，将左子树结点的前序遍历，左子树结点的中序遍历，
     * 右子树结点的前序遍历，右子树结点的中序遍历分别存到四个数组中，
     * 再将此四个数组两两配对后进行递归，即可构建二叉树
     * */
```
TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {

    // WARNing : 注意边界情况！
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    // struct TreeNode有构造函数可以直接使用
    auto *root = new TreeNode(preorder[0]);

    int n = preorder.size();
    // WARNing : 注意边界情况！
    if (n == 1) {
        return root;
    }

    int c = 0, i = 0;
    std::vector<int> preleft, preright;
    std::vector<int> inleft, inright;

    for (i = 0; i < n; i++) {
        if (preorder[0] == inorder[i]) {
            c = i;
            break;
        }
    }

    // WARNing : 存储数组时注意下标
    for (i = 0; i < c; i++) {
        preleft.push_back(preorder[i + 1]);
        inleft.push_back(inorder[i]);
    }

    for (i = c + 1; i < n; i++) {
        preright.push_back(preorder[i]);
        inright.push_back(inorder[i]);
    }

    root->left = buildTree(preleft, inleft);
    root->right = buildTree(preright, inright);

    return root;
}
```

    /*
     * 方法2
     * 方法2与原理相同，处理参数的方式略不同，
     * 但方法2的效率高于方法1，
     * 方法1由于数组存储消耗时间
     * */
```
TreeNode *buildTree2(std::vector<int> &preorder, std::vector<int> &inorder) {
    if (preorder.empty() || inorder.empty()) {
        return nullptr;
    }

    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode *build(std::vector<int> &preorder, int prestart, int preend, std::vector<int> &inorder, int instart,
                  int inend) {
    auto *root = new TreeNode(preorder[prestart]);

    int n = preorder.size();
    if (n == 1) {
        return root;
    }

    // 与方法1求根结点的方式不同，
    // 因为参数一直在变化
    int i = instart;
    while (i < inend && preorder[prestart] != inorder[i]) {
        i++;
    }

    int leftlen = i - instart;
    int rightlen = inend - i;

    // WARNing : 传入的参数画图进行确定，要准确
    if (leftlen > 0) {
        root->left = build(preorder, prestart + 1, prestart + leftlen, inorder, instart, instart + leftlen - 1);
    }

    if (rightlen > 0) {
        root->right = build(preorder, prestart + leftlen + 1, preend, inorder, instart + leftlen + 1, inend);
    }

    return root;
}
```
