/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void buildNewTree(struct TreeNode* root, int* preorder, int* inorder, int treeSize) 
{
    int count = 0;
    for (int i = 0; i < treeSize; i++) {
        if (root->val == inorder[i]) {
            break;
        }
        count++;
    }
    /*构建左叶子节点*/
    if (count != 0) {
        struct TreeNode* left = NULL;
        left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->val = preorder[1];
        left->left = NULL;
        left->right = NULL;
        root->left = left;
        buildNewTree(root->left, preorder + 1, inorder, count);
    }

    /*构建右叶子节点*/
    if (count+1 < treeSize) {
        struct TreeNode* right = NULL;
        right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        right->val = preorder[count+1];
        right->left = NULL;
        right->right = NULL;
        root->right = right;
        buildNewTree(root->right, preorder + count + 1, inorder + count + 1, treeSize - count - 1);
    }
    return;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* root = NULL;
    if (preorderSize == 0 || inorderSize == 0 || preorderSize != inorderSize) {
        return NULL;
    }
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    buildNewTree(root, preorder, inorder, preorderSize);
    return root;
}