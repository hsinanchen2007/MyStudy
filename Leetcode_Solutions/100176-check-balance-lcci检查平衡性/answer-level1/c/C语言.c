### 解题思路
此处撰写解题思路
（1）求出树的深度
（2）依次判断左右子树是否是平衡二叉树

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
int rootDepth(struct TreeNode* root)
{
    int left = 0;
    int right = 0;

    if (root == NULL) {
        return 0;
    }

    left = rootDepth(root->left) + 1;
    right = rootDepth(root->right) + 1;

    return left > right ? left : right;
}

bool isBalanced(struct TreeNode* root){
    int left, right;
    
    if (root == NULL) {
        return true;
    }

    left = rootDepth(root->left);
    right = rootDepth(root->right);

    if (abs(left - right) > 1) {
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
    }
}
```