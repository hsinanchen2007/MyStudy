### 解题思路
此处撰写解题思路

(1)求出数组长度，并开辟该长度的数组;
(2)中序遍历并保存到数组中；
(3)判断数组是否是单调递增。

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
 int g_index = 0;
int rootSize(struct TreeNode *root)
{   
    int left, right;

    if (root == NULL) {
        return 0;
    }
    left = rootSize(root->left);
    right = rootSize(root->right);

    return left + right + 1;
}

void myArrFun(struct TreeNode *root, int *arr)
{
    if (root == NULL) {
        return;
    }
    myArrFun(root->left, arr);
    arr[g_index++] = root->val;
    myArrFun(root->right, arr);
}

bool isValidBST(struct TreeNode* root){
    int sz = rootSize(root);
    int *arr = NULL;
    int i;

    if (sz <= 1) {
        return true;
    }
    g_index = 0;
    arr = (int *)malloc(sizeof(int) * sz);
    myArrFun(root, arr);

    for (i = 1; i < sz; i++) {
        if (arr[i] <= arr[i - 1]) {
            free(arr);
            return false;
        }
    }

    free(arr);
    return true;
}

```