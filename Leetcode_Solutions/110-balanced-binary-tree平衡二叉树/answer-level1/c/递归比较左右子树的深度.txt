解题思路很简单：
1.遍历树的每个节点
2.比较每个节点的左右子树的深度


int getDep(struct TreeNode *root)
{
    if (root == NULL) {
        return 0;
    }

    int left = getDep(root->left);
    int right = getDep(root->right);

    return (left > right) ? (left + 1) : (right + 1);
}

int depFabs(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    if (depFabs(getDep(root->left), getDep(root->right)) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}