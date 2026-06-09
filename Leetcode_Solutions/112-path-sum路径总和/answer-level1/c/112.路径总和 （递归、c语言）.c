### 解题思路
 遍历树，遍历的同时sum值减去当前节点的值。遍历到叶子时，如果sum减到0，则满足条件。

### 代码

```c

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) {
        return false;
    }

    /* 操作 */
    sum -= root->val;

    /* 递归结束条件 */
    if (root->left == NULL && root->right == NULL) {
        if (sum == 0) {
            return true;
        } else {
            return false;
        }
    }
    
    /* 递归 */
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}
```