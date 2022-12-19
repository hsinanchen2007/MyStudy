### 解题思路
三种情况，归到lmr和ret
不断比较最大值

### 代码
```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int i, int j) {
    if (i > j)
        return i;
    else
        return j;
}

int dfs(struct TreeNode* root, int* val) {
    if (root == NULL)
        return 0;
    
    int left = dfs(root->left, val);
    int right = dfs(root->right, val);

    int lmr = max(0, left) + root->val + max(0, right);
    int ret = root->val + max(0, max(left, right));

    *val = max(*val, lmr);
    
    return ret;
}

int maxPathSum(struct TreeNode* root){
    int val = -99999999;
    int ret = dfs(root, &val);

    return val;
}
```