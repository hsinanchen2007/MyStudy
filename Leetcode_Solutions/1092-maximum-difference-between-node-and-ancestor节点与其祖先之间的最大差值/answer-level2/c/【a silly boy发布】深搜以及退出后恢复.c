```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode TreeNode;
#define xxx(a, b) (a > b ? (a - b) : (b - a))

void subSearch(TreeNode *treeNode, int *minValue, int *maxValue,int *maxSubMinValue) {
    int tmpMinValue;
    int tmpMaxValue;

    if (treeNode == NULL) {
        if (*maxSubMinValue < (*maxValue - *minValue)) {
            *maxSubMinValue = (*maxValue - *minValue);
        }
        //之前有操作，直接回复*minValue、*maxValue的数据
        //printf("maxSubMinValue: %u\n", *maxSubMinValue);
        return;
    }
    tmpMinValue = *minValue;
    tmpMaxValue = *maxValue;

    if (*minValue >= treeNode->val) {
        *minValue = treeNode->val;
    }
    if (*maxValue <= treeNode->val) {
        *maxValue = treeNode->val;
    }

    subSearch(treeNode->left, minValue, maxValue, maxSubMinValue);
    subSearch(treeNode->right, minValue, maxValue, maxSubMinValue);

    *minValue = tmpMinValue;
    *maxValue = tmpMaxValue;
    return;
}

int maxAncestorDiff(struct TreeNode* root){
    int minValue = 0x7fffffff;
    int maxValue = 0;
    int maxSubMinValue = 0;

    int returnValue = 0;
    if (root == NULL) {
        return 0;
    }
    if ((root->left == NULL) && (root->right == NULL)) {
        return 0;
    }

    subSearch(root, &minValue, &maxValue, &maxSubMinValue);
    returnValue = maxSubMinValue;
    //printf("returnValue: %u\n", returnValue);

    return returnValue;
}
```
