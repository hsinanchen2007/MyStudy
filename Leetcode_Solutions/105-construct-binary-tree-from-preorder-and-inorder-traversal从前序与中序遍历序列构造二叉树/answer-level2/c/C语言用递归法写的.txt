C语言用递归法写的

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    struct TreeNode* newNode;
    int p = 0;
    int i = 0;

    if (preorder == NULL || inorder == NULL) {
        return NULL;
    }
    if (preorderSize <= 0 || inorderSize <= 0) {
        return NULL;
    }

    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = preorder[p];
    newNode->left = NULL;
    newNode->right = NULL;
    
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == newNode->val) {
            newNode->left = buildTree(&preorder[p + 1], i, inorder, i);
            newNode->right = buildTree(&preorder[p + i + 1], preorderSize - i - 1, &inorder[i + 1], inorderSize - i - 1);
            break;
        }
    }

    return newNode;
}