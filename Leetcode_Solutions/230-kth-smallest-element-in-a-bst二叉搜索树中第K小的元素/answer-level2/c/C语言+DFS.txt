### 解题思路
此处撰写解题思路

（1）前序遍历数组并保存元素；
（2）返回数组中第k个元素即可

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

int nodeSize(struct TreeNode *root)
{
    int left, right;

    if (root == NULL) {
        return 0;
    }

    left = nodeSize(root->left);
    right = nodeSize(root->right);

    return left + right + 1;
}

void toArr(struct TreeNode *root, int *arr)
{
    if (root == NULL) {
        return;
    }

    toArr(root->left, arr);
    arr[g_index++] = root->val;
    toArr(root->right, arr);
}

int kthSmallest(struct TreeNode* root, int k){
    int sz = nodeSize(root);
    int *arr = (int *)malloc(sizeof(struct TreeNode) * sz);
    int res;
    g_index = 0;

    toArr(root, arr);
    res = arr[k - 1];
    free(arr);

    return res;
}
```