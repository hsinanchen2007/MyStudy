### 解题思路
和105题一样，是一菜两吃
![image.png](https://pic.leetcode-cn.com/6410f699eb42491cf6c48df257e30acd300a0e5cf9961f467e24f19df1629d20-image.png)

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

int findInx(int *inorder, int inorderSize, int target)
{
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == target) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int left, right;
    int n_inx;
    struct TreeNode *n = NULL;
    if (postorderSize <= 0) {
        return NULL;
    }
    n = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (n == NULL) {
        return NULL;
    }
    n->val = postorder[postorderSize - 1];
    n_inx = findInx(inorder, inorderSize, n->val);
    if (n_inx < 0) {
        return NULL;
    }
    left = n_inx;
    right = inorderSize - n_inx - 1;
    n->left = buildTree(inorder, left, postorder, left);
    n->right = buildTree(inorder + n_inx + 1, right, postorder + left, right);
    return n;
}
```