### 解题思路
    /*
     * 递归遍历
     *
     * 因为二叉搜索树的性质是左节点的值小于根节点的值小于右节点的值，
     * 而最低公共祖先节点的值必然在两给定节点值中间，包括两端。
     * 所以将父节点的值与给定两节点的值进行比较：
     * 1. 如果父节点值在两节点值中间，返回父节点；
     * 2. 如果两节点值都大于父节点值，则遍历右子树；
     * 3. 如果两节点值都小于父节点值，则遍历左子树。
     * */
### 代码

```cpp
BiTreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || p == nullptr || q == nullptr) {
        return nullptr;
    }

    // 使用差乘的正负判断是否父节点是否在两节点之间，
    // 减少判断次数
    if (((root->val - q->val) * (root->val - p->val)) <= 0) {
        return root;
    }

    // 因为p和q要么比root大，要么比root小，
    // 所以只需要将父节点与一个节点比较即可
    // 如果两节点都比父节点小，遍历左子树
    if (p->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // 如果两节点都比父节点大，遍历右子树
    if (p->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    return nullptr;
}
``` 