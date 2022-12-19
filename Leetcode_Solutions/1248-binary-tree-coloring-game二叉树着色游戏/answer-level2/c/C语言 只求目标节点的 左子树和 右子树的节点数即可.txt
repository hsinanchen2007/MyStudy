/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define strstok_s(strToken, strDelimit, context) strstok(strToken, strDelimit)

#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) > (b) ? (b) : (a))

int TreeCountLeftRight(const struct TreeNode* root, int x, int* leftChild, int* rightChild)
{
    if (root == NULL || (*leftChild != -1 && *rightChild != -1)) {
        return 0;
    }
    int left = 0;
    int right = 0;
    
    left = TreeCountLeftRight(root->left, x, leftChild, rightChild);
    right = TreeCountLeftRight(root->right, x, leftChild, rightChild);
    if (root->val == x) {
        *leftChild = left;
        *rightChild = right;
    }
    return left + right + 1;
}


bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    if (root == NULL || n == 1 || n == 2) {
        return false;
    }

    int leftChild = -1;
    int rightChild = -1;
    TreeCountLeftRight(root, x, &leftChild, &rightChild);
    if (root->val == x) {
        return n - leftChild < leftChild || 
        n - rightChild < rightChild;
    }

    return leftChild + rightChild + 1 < n - leftChild - rightChild - 1 || 
        n - leftChild < leftChild || 
        n - rightChild < rightChild;
}
