先上代码
```
int rob(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int robthat = root->val;
    if (root->left != NULL) {
        robthat += rob(root->left->left) + rob(root->left->right);
    }
    if (root->right != NULL) {
        robthat += rob(root->right->left) + rob(root->right->right);
    }
    int norob = rob(root->left);
    norob    += rob(root->right);
    int ret = robthat > norob ? robthat :norob;
    return ret;
}
```
假设每个节点中都存着以当前节点为根节点的**最大值**。
对树中任意一个节点的操作，只有偷或不偷两种操作：
如果不偷当前节点：则当前节点值 = 左子节点 + 右子节点。（保证当前节点存的值最大）
如果偷当前节点：  则当前节点值 = 当前节点 + 左子节点的左子节点 +  左子节点的右子节点 + 右子节点左子节点 + 右子节点右子节点