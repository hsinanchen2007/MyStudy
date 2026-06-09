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

void traverse(struct TreeNode *root, int * tmp, int *tmpSize) {
    if (root == NULL) {
        return;
    }
    traverse(root->left, tmp, tmpSize);
    tmp[(*tmpSize)++] = root->val;
    traverse(root->right, tmp, tmpSize);
}

struct TreeNode* construct(int *tmp, int start, int end)
{
    printf("%d,%d\n", start, end);
    if (start > end) {
        return NULL;
    }
    struct TreeNode* newroot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int middle = (start + end)/2;
    newroot->val = tmp[middle];
    newroot->left = construct(tmp, start, middle - 1);
    newroot->right = construct(tmp, middle + 1, end);
    return newroot;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    int tmp[10240];
    int tmpSize = 0;
    int start = 0;
    int end = 0;
    traverse(root, tmp, &tmpSize);

    for (int i = 0; i < tmpSize; i++) {
        printf("%d\n", tmp[i]);
    }

    end = tmpSize - 1;
    struct TreeNode *newroot = NULL;
    newroot = construct(tmp, start, end);
    return newroot;
}
```