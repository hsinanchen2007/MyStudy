/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int curLevel = 0;
int maxLeftLevel = 0;
struct TreeNode *maxLeftNode = NULL;
int findBottomLeftValue(struct TreeNode* root){

    struct TreeNode *curNode = root;
    if (curLevel == 0)
    {
        maxLeftNode = root;
    }
    curLevel++;
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL && curLevel > maxLeftLevel)
    {
        maxLeftNode = root;
        maxLeftLevel = curLevel;
    }


    findBottomLeftValue(root->left);
    curLevel--;
    findBottomLeftValue(root->right);
    curLevel--;
    
    if (curLevel == 1)
    {
        curLevel = 0;
        maxLeftLevel = 0;
    }
    return maxLeftNode->val;
}
空间换时间 8ms 10M内存