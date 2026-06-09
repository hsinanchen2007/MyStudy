### 解题思路
    /*
     * 递归法 -- 节点多次遍历
     *
     * 先递归计算左右子树的深度，判断左右子树是否平衡，如果左右深度差大于1则不平衡。
     * 如果平衡，再对左右子树的左右子树进行递归判断是否平衡。
     * 这样存在的问题是，在计算左右子树深度时已经遍历过二叉树左右子树的左右子树，
     * 所以这样计算会导致多次对二叉树节点进行遍历，增加开销。
     * */
### 代码

```cpp
bool isBalanced(TreeNode *root) {
    if (root == nullptr) {
        return true;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 左右子树深度差
    int diff = leftDepth - rightDepth;
    // 如果大于1则不平衡
    if (diff > 1 || diff < -1) {
        return false;
    }

    // 对左右子树进行递归判断
    return isBalanced(root->left) && isBalanced(root->right);
}

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }

    // 递归左子树
    int leftDepth = maxDepth(root->left);
    // 递归右子树
    int rightDepth = maxDepth(root->right);

    // 返回左右子树深度较大的值加1
    return std::max(leftDepth, rightDepth) + 1;
}
```

### 解题思路
    /*
     * 递归法 -- 节点单次遍历
     *
     * 为避免对二叉树的节点进行多次遍历，可以在遍历二叉树的过程中就计算二叉树的深度。
     * 因为后序遍历在访问每个节点前就已经遍历过它的左右子树。只要在遍历每个节点时，
     * 记录该节点的深度，即该节点到叶节点路径的深度，就可以边遍历边判断每个节点是否是平衡的。
     * */
### 代码

```cpp
bool isBalanced(TreeNode *root) {
    int depth = 0;
    return balance(root, depth);
}

bool balance(TreeNode *root, int &depth) {
    // 叶节点是平衡的，且深度为0
    if (root == nullptr) {
        depth = 0;
        return true;
    }

    // 定义左右子树的深度
    // 定义左右子树的深度差
    int left = 0, right = 0, diff = 0;

    // 如果该节点的左右子树是平衡的
    if (balance(root->left, left) && balance(root->right, right)) {
        // 则当前节点的左右子树根据返回的深度计算差
        diff = left - right;
        // 如果深度差小于1则是平衡的
        if (diff <= 1 && diff >= -1) {
            // 同时当前节点的深度为左右子树深度较大值加1
            depth = 1 + (left > right ? left : right);
            return true;
        }
    }

    return false;
}
```