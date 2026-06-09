### 解题思路 递归遍历法
    /*
     * 递归遍历法
     *
     * 原始的二叉树如下：
     *         4
     *       /   \
     *      2     7
     *     / \   / \
     *    1   3 6   9
     *
     * 对根节点的左右子树交换后如下：
     *    --------->
     *
     *         4
     *       /   \
     *      7     2
     *     / \   / \
     *    6   9 1   3
     *
     * 对根节点的左右子树的左右子树进行递归后交换如下：
     *    --------->
     *
     *         4
     *       /   \
     *      7     2
     *     / \   / \
     *    9   6 3   1
     *
     * 如上二叉树的递归交换过程，只需要先对根节点的左右子树交换，
     * 在对根节点的左右子树递归遍历后，对其左右子树的左右子树交换即可。
     * */

### 代码

```cpp
BiTreeNode *mirrorTree(BiTreeNode *root) {
    if (root == nullptr) {
        return nullptr;
    }

    // 如果左右子树为空时，返回根节点
    if (root->left == nullptr && root->right == nullptr) {
        return root;
    }

    // 交换左右子树
    BiTreeNode *tempNode = root->left;
    root->left = root->right;
    root->right = tempNode;

    // 对左子树递归
    if (root->left) {
        mirrorTree(root->left);
    }

    // 对右子树递归
    if (root->right) {
        mirrorTree(root->right);
    }

    return root;
}
```