### 解题思路
直接上代码

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
int depth(struct TreeNode* root, int *diameter) {
    if (!root) {
        return 0;
    }
    int left = depth(root->left, diameter);
    int right = depth(root->right, diameter);
    int current = left + right + 1;
    *diameter = (*diameter) > current ? (*diameter) : current;
    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if (!root) {
        return 0;
    }
    int *diameter = (int *)malloc(sizeof(int));
    *diameter = 1;
    depth(root, diameter);
    int ret = *diameter - 1;
    return ret;
}
```