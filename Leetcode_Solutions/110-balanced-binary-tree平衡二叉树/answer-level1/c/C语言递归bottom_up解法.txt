### 解题思路
递归bottom_up求解树问题

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
bool isbanlance = true;

int findheight(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    if (!isbanlance) {
        return 0;
    }
    int lh = findheight(root->left) + 1;
    int rh = findheight(root->right) + 1;

    if(lh - rh > 1 || rh - lh > 1) {
        isbanlance = false;
    }
    return lh > rh ? lh : rh;
}

bool isBalanced(struct TreeNode* root){
    isbanlance = true;
    findheight(root);
    return isbanlance;
}
```