**思路**
我也不知道这叫什么办法==
构一个函数，每执行一次z函数，则将左右叶节点上的结果相加放到根节点上。
函数执行的次数就是计算的层数，每次计算返回最上面那个点的值就是该层的和。

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int CalcSum(struct TreeNode* root)
{
    if (root->left == NULL && root->right == NULL) {
        root->val = 0;
    } else if(root->left != NULL && root->right == NULL) {
        root->val = (root->left)->val;
        (root->left)->val = CalcSum(root->left);
    } else if(root->right != NULL && root->left == NULL) {
        root->val = (root->right)->val;
        (root->right)->val = CalcSum(root->right);
    } else {
        root->val = (root->left)->val + (root->right)->val;
        (root->left)->val = CalcSum(root->left);
        (root->right)->val = CalcSum(root->right);
    }    
    return root->val;
}

int maxLevelSum(struct TreeNode* root){
    int layer = 0;
    int sum = 0;
    int out = 0;
    int idx = 1;
    while (idx) {
        int tmp = root->val;
        layer++;
        out = (tmp > sum) ? layer : out;
        sum = (tmp > sum) ? tmp : sum;
        idx = CalcSum(root);
    }
    return out;
}

```
