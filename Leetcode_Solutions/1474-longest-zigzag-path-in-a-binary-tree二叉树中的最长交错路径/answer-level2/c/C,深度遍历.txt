### 解题思路
1. left：当前root节点的左子树的最大zigzag，即root->left为根的子树的right+1
2. right：当前root节点的右子树的最大zigzag，即root->right为根的子树的left+1
3. max：曾出现的最大zigzag：为（root->left的max， root->right的max， right+1, left+1）的最大值

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

void dfs(struct TreeNode *root, int *left, int *right, int *max) {

    if (root->left == NULL && root->right == NULL) {
        *left = *right = *max = 0;
        return;
    }

    int lleft = 0;
    int lright = 0;
    int lmax = 0;
    if (root->left) {
        dfs(root->left, &lleft, &lright, &lmax);
        *left = lright+1;
    }

    int rleft = 0;
    int rright = 0;
    int rmax = 0;
    if (root->right) {
        dfs(root->right, &rleft, &rright, &rmax);
        *right = rleft+1;
    }

    *max = fmax(lmax, fmax(rmax, fmax(*left, *right)));
    //printf("node %d: L %d R %d M %d\n", root->val, *left, *right, *max);
    return;
}


int longestZigZag(struct TreeNode* root){
    if (!root) return 0;

    int left = 0;
    int right = 0;
    int max = 0;
    dfs(root, &left, &right, &max);
    return max;
}
```