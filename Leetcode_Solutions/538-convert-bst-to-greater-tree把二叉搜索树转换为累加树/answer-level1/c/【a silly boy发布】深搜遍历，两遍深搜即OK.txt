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

void SubTreeSum(TreeNode *treeNode, int *outSum) {
    if (treeNode == NULL) {
        return;
    }
    *outSum = *outSum + treeNode->val;
    SubTreeSum(treeNode->left, outSum);
    SubTreeSum(treeNode->right, outSum);
}

void SubTreeRenew(TreeNode *treeNode, int *outSum) {
    int tmpValue;
    if (treeNode == NULL) {
        return;
    }

    SubTreeRenew(treeNode->left, outSum);

    tmpValue = treeNode->val;
    treeNode->val += *outSum - tmpValue;
    *outSum = *outSum - tmpValue;

    SubTreeRenew(treeNode->right, outSum);
}

struct TreeNode* convertBST(struct TreeNode* root){
    int outSum = 0;
    if (root == NULL) {
        return root;
    }
    SubTreeSum(root, &outSum);
    //printf("outSum: %u\n", outSum);
    SubTreeRenew(root, &outSum);
    
    return root;
}
```
