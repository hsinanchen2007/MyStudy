### 解题思路
（1）直接定义了一个大内存，这个也可能有好的办法解决，比如：
int TreeSize(struct TreeNode *root)
{
    if(root == NULL)    return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}
（2）首次提交的时候失败，外部传入的returnSize， 直接使用*returnSize， 需要先复制一个初值
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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define  MAX  10000

void traver(struct TreeNode* root, int* returnSize, int* out)
{
    if (root == NULL) {
        return;
    }

    traver(root->left, returnSize, out);
    out[*returnSize] = root->val;
    *returnSize = *returnSize + 1;
    traver(root->right, returnSize, out);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int* out = (int*) malloc(MAX * sizeof(int));
    if (out == NULL) {
        return NULL;
    }
    *returnSize = 0;
    memset(out, 0, MAX * sizeof(int));
    traver(root, returnSize, out);
    return out;
}


```