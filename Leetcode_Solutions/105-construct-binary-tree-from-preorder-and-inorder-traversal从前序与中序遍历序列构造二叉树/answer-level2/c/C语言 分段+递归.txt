### 解题思路
这道题目真不错，以前只是由树做遍历生成数组，并未仔细观察过生成数组的特点。
递归生成的数组本身就具备着递归基因，分段特点明显，一看就是分治法的菜。
![image.png](https://pic.leetcode-cn.com/63176a3d4e0d64f23b2d14677e649543534b0e0c7b1e7ac74c24253ceba86fe1-image.png)

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

int findNode(int *inorder, int inorderSize, int target)
{
    int i;
    for (i = 0; i < inorderSize; i++) {
        if (inorder[i] == target) {
            return i;
        }
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int n_inx;
    int left, right;
    struct TreeNode *n = NULL;
    if (preorderSize <= 0) {
        return NULL;
    }
    n = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (n == NULL) {
        return NULL;
    }
    n->val = preorder[0];
    n_inx = findNode(inorder, inorderSize, n->val);
    if (n_inx < 0) {
        return NULL;
    }
    left = n_inx;
    right = inorderSize - n_inx - 1;
    n->left = buildTree(preorder + 1, left, inorder, left);
    n->right = buildTree(preorder + 1 + left, right, inorder + n_inx + 1, right);
    return n;
}
```