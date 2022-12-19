### 解题思路
此处撰写解题思路

将问题拆解成三部分即可。

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

 //这个函数只找包含root的路径
int myPathSum(struct TreeNode *root, int sum)
{
    int cnt = 0;

    if (root == NULL) {
        return 0;
    }

    if (root->val == sum) {
        cnt++;
    }

    cnt += myPathSum(root->left, sum - root->val);
    cnt += myPathSum(root->right, sum - root->val);

    return cnt;
}

int pathSum(struct TreeNode* root, int sum){
    int res = 0;
    if (!root) {
        return res;
    }
    return myPathSum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

```