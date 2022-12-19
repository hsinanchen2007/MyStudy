![E8F33615-9EB0-40D1-A30A-C9027D3AB0D4.jpeg](https://pic.leetcode-cn.com/53c004f0242042ae8f95b85504dbb22033bc67601a76093320549a26f630a5b2-E8F33615-9EB0-40D1-A30A-C9027D3AB0D4.jpeg)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool SubFuncDFS(struct TreeNode* root, int sum, int tmpSum)
{
    bool returnVal = false;
    tmpSum = tmpSum + root->val;
    if ((tmpSum != sum) && (root->left == NULL) && (root->right == NULL)) {
        return false;
    }
    if (tmpSum == sum) {
        if ((root->left == NULL) && (root->right == NULL)) {
            return true;
        }
    }
    if (root->left != NULL) {
        returnVal = SubFuncDFS(root->left, sum, tmpSum);
        if (returnVal == true) {
            return true;
        }
    }
    if (root->right != NULL) {
        returnVal = SubFuncDFS(root->right, sum, tmpSum);
        if (returnVal == true) {
            return true;
        }
    }

    return returnVal;
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    bool returnVal = false;
    int tmpSum = 0;
    if (root == NULL) {
        return false;
    }
    returnVal = SubFuncDFS(root, sum, tmpSum);

    return returnVal;
}
```
