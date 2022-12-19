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

typedef struct TreeNode NODE;

int g_sum = 0;

void dfs(NODE* root, int* tempnum) {
    int temp = 0;

    if(root == NULL) {
        return;
    }
    temp = (*tempnum) * 10 + root->val;
    if(root->left == NULL && root->right == NULL) {
        g_sum = g_sum + temp;
        printf("temp = %d", temp);
    }
    dfs(root->left, &temp);
    dfs(root->right, &temp);
}


int sumNumbers(struct TreeNode* root){
    int result = 0;
    int tempnum = 0;

    g_sum = 0;
    dfs(root, &tempnum);

    return g_sum;
}
```