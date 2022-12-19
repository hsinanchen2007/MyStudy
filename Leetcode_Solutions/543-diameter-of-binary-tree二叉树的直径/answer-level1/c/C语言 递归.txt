### 解题思路
递归过程中更新最大直径，返回单边最大边数
![image.png](https://pic.leetcode-cn.com/2b81d3437fca7d0b16de4d79478286c9326612bcca2aed183d43dc6fc7aab9a9-image.png)

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

int proc(struct TreeNode *root, int *max)
{
    int left, right, cur;
    if (root == NULL) {
        return -1;
    }
    left = proc(root->left, max);
    right = proc(root->right, max);
    cur = left + right + 2;
    *max = *max > cur ? *max : cur;
    return (left > right ? left : right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int max = 0;
    proc(root, &max);
    return max;
}
```