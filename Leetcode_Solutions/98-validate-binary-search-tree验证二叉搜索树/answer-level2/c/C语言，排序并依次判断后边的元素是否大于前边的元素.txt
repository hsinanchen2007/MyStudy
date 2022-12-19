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

int g_cnt = 0;

void rootSize(struct TreeNode *root)
{
    g_cnt++;
    if (root->left) {
        rootSize(root->left);
    }
    if (root->right) {
        rootSize(root->right);
    }
}

void myArr(struct TreeNode *root, int *cnt, int *arr)
{
    if (root == NULL) {
        return;
    }
    if (root->left) {
        myArr(root->left, cnt, arr);
    }

    arr[*cnt] = root->val;
    (*cnt)++;

    if (root->right) {
        myArr(root->right, cnt, arr);
    }
}

bool isValidBST(struct TreeNode* root){
    int *arr = NULL;
    int index = 0;
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }
    g_cnt = 0;
    rootSize(root);
    arr = (int *)malloc(sizeof(int) * g_cnt);
    myArr(root, &index, arr);

    for (index = 1; index < g_cnt; index++) {
        if (arr[index] <= arr[index - 1]) {
            return false;
        }
    }

    return true;
}
```