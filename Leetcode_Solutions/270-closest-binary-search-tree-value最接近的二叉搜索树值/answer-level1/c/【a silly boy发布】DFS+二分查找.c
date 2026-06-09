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

#define ABSDEF(a, b) ((a > b) ? (double)(a - b) : (double)(b - a))

void SubFuncBFS(TreeNode* root, double target, double *dValue, int *outputValue)
{
    int val;
    if (root == NULL) {
        return;
    }
    val = root->val;

    if (ABSDEF(target, val) <= *dValue) {
        *dValue = ABSDEF(target, val);
        //printf("ABSDEF(target, val): %f, dValue: %f\n", ABSDEF(target, val), *dValue);
        *outputValue = val;
    }

    SubFuncBFS(root->left, target, dValue, outputValue);
    SubFuncBFS(root->right, target, dValue, outputValue);
}

void Tree2Search(TreeNode* root, double target, double *dValue, int *outputValue)
{
    int val;
    if (root == NULL) {
        return;
    } 
    val = root->val;

    if (ABSDEF(target, val) <= *dValue) {
        *dValue = ABSDEF(target, val);
        //printf("ABSDEF(target, val): %f, dValue: %f\n", ABSDEF(target, val), *dValue);
        *outputValue = val;
    }

    if (val > target) {
        SubFuncBFS(root->left, target, dValue, outputValue);
    } else {
        SubFuncBFS(root->right, target, dValue, outputValue);
    }
}

int closestValue(struct TreeNode* root, double target){
    if (root == NULL) {
        return 0;
    }

    int outputValue = 0;
    double dValue = ABSDEF(target, root->val) ;

    //SubFuncBFS(root, target, &dValue, &outputValue);
    Tree2Search(root, target, &dValue, &outputValue);

    return outputValue;
}
```
