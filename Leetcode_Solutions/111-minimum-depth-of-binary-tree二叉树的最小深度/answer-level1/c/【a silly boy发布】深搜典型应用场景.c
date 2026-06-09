//深搜典型应用场景
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

void subFuncMinDepth(TreeNode *treeNode, int inputDepth, int *outputDepth) {

    if ((treeNode->left == NULL) && (treeNode->right == NULL)) {
        if (*outputDepth > inputDepth) {
            *outputDepth = inputDepth;
        }
        //printf("*outputDepth: %u\n", *outputDepth);
        return;
    }
    inputDepth++;
    if (treeNode->left != NULL) {
        subFuncMinDepth(treeNode->left, inputDepth, outputDepth);
    }
    if (treeNode->right != NULL) {
        subFuncMinDepth(treeNode->right, inputDepth, outputDepth);
    }
}

int minDepth(struct TreeNode* root){
    int returnValue = 0xffff;
    int inputDepth = 0;
    
    if (root == NULL) {
        return 0;
    }

    subFuncMinDepth(root, inputDepth, &returnValue);

    return returnValue + 1;
}
```
