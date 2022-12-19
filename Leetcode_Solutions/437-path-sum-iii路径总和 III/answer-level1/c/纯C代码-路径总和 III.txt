### 解题思路
此处撰写解题思路

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
void calculatePath(struct TreeNode *root, int sum, int *cnt){
    int remain = 0;
    if (root == NULL){
        return;
    }

    remain = sum - root->val;
    if (remain == 0){
        (*cnt)++;
    }
    calculatePath(root->left, remain, cnt);
    calculatePath(root->right, remain, cnt);

    return;
}


int pathSum(struct TreeNode* root, int sum){
    int cnt = 0;

    if (root == NULL){
        return 0;
    }
    calculatePath(root, sum, &cnt);
    cnt += pathSum(root->left, sum);
    cnt += pathSum(root->right, sum);

    return cnt;
}
```