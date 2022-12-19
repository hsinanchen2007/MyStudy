深度优先搜索，避免重复计算：
1、先判断左子树，右子树是不是二叉搜索树；
2、如果左右子树都是二叉搜索树，那么再判断根结点组成的树是否是二叉搜索树；
注：不能仅root->val跟root->left->val、root->right->val判断，还需要跟左子树的最大值以及右子树的最小值比较
```
#define MAX_VALUE 40001
int Max(int a, int b)
{
    return a > b ? a : b;
}
int Min(int a, int b)
{
    return a < b ? a : b;
}
int g_maxSum;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool CalculateMaxSumBST(struct TreeNode *root, int *sum, int *max, int *min)
{
    int leftSum = 0;
    int rightSum = 0;
    int leftMaxValue = -MAX_VALUE;
    int leftMinValue = MAX_VALUE;
    int rightMaxValue = -MAX_VALUE;
    int rightMinValue = MAX_VALUE;
    bool leftIsBSTTree = false;
    bool rightIsBSTTree = false;
    if (root == NULL) {
        return true;
    }

    leftIsBSTTree = CalculateMaxSumBST(root->left, &leftSum, &leftMaxValue, &leftMinValue);
    rightIsBSTTree = CalculateMaxSumBST(root->right, &rightSum, &rightMaxValue, &rightMinValue);
    if (leftIsBSTTree && rightIsBSTTree) {
        if (root->left != NULL) {
            if (root->val <= root->left->val) {
                return false;
            }
            if (root->val <= leftMaxValue) {
                return false;
            }
            *sum += leftSum;
        }
        *min = Min(root->val, leftMinValue);
        if (root->right != NULL) {
            if (root->val >= root->right->val) {
                return false;
            }
            if (root->val >= rightMinValue) {
                return false;
            }
            *sum += rightSum;
        }
        *max = Max(root->val, rightMaxValue);
        *sum += root->val;
        g_maxSum = Max(g_maxSum, *sum);
        return true;
    }
    return false;
}
int maxSumBST(struct TreeNode* root){
    int sum = 0;
    int maxValue = -MAX_VALUE;
    int minValue = MAX_VALUE;
    g_maxSum = 0;
    CalculateMaxSumBST(root, &sum, &maxValue, &minValue);
    return g_maxSum;
}
```
